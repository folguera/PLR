# for model building:
def get_model(signalname):

    # Read in and build the model automatically from the histograms in the root file. 
    # This model will contain all shape uncertainties given according to the templates
    # which also includes rate changes according to the alternate shapes.
    # For more info about this model and naming conventuion, see documentation
    # of build_model_from_rootfile.
    model = build_model_from_rootfile('Template_JES_JER_BTag_LES_Q2_Mpts.root',  include_mc_uncertainties=True)
    #model = build_model_from_rootfile('Template_JER_BTag_LES_Q2_Mpts.root',      include_mc_uncertainties=True)
    #model = build_model_from_rootfile('Template_JES_BTag_LES_Q2_Mpts.root',      include_mc_uncertainties=True)
    #model = build_model_from_rootfile('Template_JES_JER_LES_Q2_Mpts.root',       include_mc_uncertainties=True)
    #model = build_model_from_rootfile('Template_JES_JER_BTag_Q2_Mpts.root',      include_mc_uncertainties=True)
    #model = build_model_from_rootfile('Template_JES_JER_BTag_LES_Mpts.root',     include_mc_uncertainties=True)
    #model = build_model_from_rootfile('Template_JES_JER_BTag_LES_Q2.root',       include_mc_uncertainties=True)

    # If the prediction histogram is zero, but data is non-zero, teh negative log-likelihood
    # is infinity which causes problems for some methods. Therefore, we set all histogram
    # bin entries to a small, but positive value:
    model.fill_histogram_zerobins()

    # define what the signal processes are. All other processes are assumed to make up the 
    # 'background-only' model.
    model.set_signal_processes('ttbar')

    # Add some lognormal rate uncertainties. The first parameter is the name of the
    # uncertainty (which will also be the name of the nuisance parameter), the second
    # is the 'effect' as a fraction, the third one is the process name. The fourth parameter
    # is optional and denotes the channl. The default '*' means that the uncertainty applies
    # to all channels in the same way.
    # Note that you can use the same name for a systematic here as for a shape
    # systematic. In this case, the same parameter will be used; shape and rate changes 
    # will be 100% correlated.
    
    
    
    #model.add_lognormal_uncertainty('ttbar_rate', math.log(1.0), 'ttbar')
    #model.distribution.set_distribution_parameters('ttbar_rate', width=1000000) 
    
    model.add_lognormal_uncertainty('stop_rate', math.log(1.2), 'stop')
    model.add_lognormal_uncertainty('dy_rate',   math.log(1.2), 'dy'  )
    model.add_lognormal_uncertainty('rare_rate', math.log(1.5), 'rare')
    model.add_lognormal_uncertainty('fake_rate', math.log(1.5), 'fake')

	
	
    # the qcd model is from data, so do not apply a lumi uncertainty on that:
    for p in model.processes:
    	#if p == 'dy': continue
    	#if p == 'fake': continue
    	model.add_lognormal_uncertainty('lumi',    math.log(1.026), p)
        model.add_lognormal_uncertainty('Trig',    math.log(1.023) , p)
	
	
	
        #model.add_lognormal_uncertainty('Brs',     math.log(1.05) , p)
    # Specifying all uncertainties manually can be error-prone. You can also execute
    # a automatically generated file using python's execfile here
    # which contains these statements, or read in a text file, etc. Remember: this is a
    # python script, so use this power!
    return model

# -------------- TO CHANGE BY THE USER
signalname = 'ttbar'
# -------------- TO CHANGE BY THE USER
model = get_model(signalname)


# first, it is a good idea to generate a summary report to make sure everything has worked
# as expected. The summary will generate quite some information which should it make easy to spot
# errors like typos in the name of uncertainties, missing shape uncertaintie, etc.
model_summary(model)




# 2.b. CLs limits
# calculate cls limit plots. The interface is very similar to bayesian_limits. However, there are a few
# more options such as the definition of the test statistic which is usually a likelihood ratio but can differ in
# which parameters are minimized and which constraints / ranges are applied during minimization.
# Here, we stay with the default which fixes beta_signal=0
# for the background only hypothesis and lets it float freely for the signal+background hypothesis.
# See cls_limits documentation for more options.

#

signal_shapes = {'ttbar': ['ttbar']}  

one_sigma = 0.6827
two_sigma = 0.95

res = pl_interval(model, 'data', n=1, cls = [one_sigma], signal_process_groups = signal_shapes )


#res = pl_interval(model, 'toys:0', n=1, signal_process_groups = signal_shapes )


#twi keys 'ttbar' and the interval "one_sigma", it returns a list of double entries : lower and upper bound
print [ res['ttbar'][0][0] , res['ttbar'][one_sigma][0][0] , res['ttbar'][one_sigma][0][1] ]

  
  

resnll = nll_scan(model, 'data', n=10,  npoints=100, range=[0.8, 1.2])


finalplot = resnll['ttbar'][0]
finalplot.write_txt('PRL.txt')
#finalplot.histo()





### For max. Likelihood Fit results

fit = mle(model, input = 'data', n = 1, signal_process_groups = signal_shapes, with_covariance=True, with_error=True, ks = True, chi2 = True)

# the output is (fitted value, uncertainty)
# The first numbers in the brackets show how far we are from the nominal value (which is 0) after the fit. 
#A value of 1 would mean 1 sigma deviation. So we are below 1 sigma deviation. 
#The second numbers in the brackets illustrates the uncertainty on the fitted value, it should be below 1, 
#and a value close to 1 corresponds to "no sensitivity" on the systematic.

parameter_values = {}
parameter_uncert = {}
for p in model.get_parameters([]):
    parameter_values[p] = fit['ttbar'][p][0][0]
    parameter_uncert[p] = fit['ttbar'][p][0][1]
    
    print [p, parameter_values[p], parameter_uncert[p] ]



parameter_values['beta_signal'] =  res['ttbar'][0][0]


histos = evaluate_prediction(model, parameter_values, include_signal = True)
write_histograms_to_rootfile(histos, 'histos-mle_ttbar.root')


ttbar_init_xs = 245.8


ttbar_fit  = ttbar_init_xs*res['ttbar'][0][0]
ttbar_down = ttbar_init_xs*res['ttbar'][one_sigma][0][0]
ttbar_up   = ttbar_init_xs*res['ttbar'][one_sigma][0][1] 

print ["fitted cross section ", ttbar_fit]
print ["down variation       ", ttbar_down]
print ["up variation         ", ttbar_up]

report = model_summary(model)
#report.write_html('htmlout')


