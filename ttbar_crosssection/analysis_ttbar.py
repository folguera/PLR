dosysttable = True

dobiasscan  = True

# for model building:
def get_model(signalname):

    # Read in and build the model automatically from the histograms in the root file. 
    # This model will contain all shape uncertainties given according to the templates
    # which also includes rate changes according to the alternate shapes.
    # For more info about this model and naming conventuion, see documentation
    # of build_model_from_rootfile.
    model = build_model_from_rootfile('RootFiles/Template_JES_JER_BTag_LES_Q2_Mpts.root',  include_mc_uncertainties=True)
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
    
    model.add_lognormal_uncertainty('stop_rate', math.log(1.22), 'stop')
    model.add_lognormal_uncertainty('dy_rate',   math.log(1.21), 'dy'  )
    model.add_lognormal_uncertainty('rare_rate', math.log(1.20),  'rare')
    model.add_lognormal_uncertainty('fake_rate', math.log(1.99), 'fake')
    model.add_lognormal_uncertainty('vv_rate',   math.log(1.23), 'vv'  )

	
	
    # the qcd model is from data, so do not apply a lumi uncertainty on that:
    for p in model.processes:
    	#if p == 'dy': continue
    	if p == 'fake': continue
    	model.add_lognormal_uncertainty('lumi',        math.log(1.026), p)
        model.add_lognormal_uncertainty('TrigLept',    math.log(1.02), p)
	
	
	
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

print ("measurement of the cross-section")
res = pl_interval(model, 'data', n=1, cls = [one_sigma], signal_process_groups = signal_shapes )
#twi keys 'ttbar' and the interval "one_sigma", it returns a list of double entries : lower and upper bound
print [ "%.3f" % res['ttbar'][0][0] , "%.3f" %res['ttbar'][one_sigma][0][0] , "%.3f" %res['ttbar'][one_sigma][0][1] ]

ttbar_init_xs = 245.8


ttbar_fit  = ttbar_init_xs*res['ttbar'][0][0]
ttbar_down = ttbar_init_xs*res['ttbar'][one_sigma][0][0]
ttbar_up   = ttbar_init_xs*res['ttbar'][one_sigma][0][1] 

print ["fitted cross section ", "%.1f" %ttbar_fit]
print ["down variation       ", "%.1f" %ttbar_down]
print ["up variation         ", "%.1f" %ttbar_up]


syst_down   = (res['ttbar'][0][0] - res['ttbar'][one_sigma][0][0])/res['ttbar'][0][0]
syst_up     = (res['ttbar'][one_sigma][0][1] - res['ttbar'][0][0])/res['ttbar'][0][0]

print ["systdown/up (%)" , "%.1f" %(syst_down*100), "%.1f" %(syst_up*100)]
print ["final cross section ", "%.1f" %ttbar_fit, "-", "%.1f" %(syst_down*ttbar_fit), "+", "%.1f" %(syst_up*ttbar_fit)]


resnll = nll_scan(model, 'data', n=1,  npoints=100, range=[0.8, 1.2])


finalplot = resnll['ttbar'][0]
finalplot.write_txt('PRL.txt')
#finalplot.histo()


print ("------------------------------------------------------------------")
print ("------------------------------------------------------------------")


### For max. Likelihood Fit results

fit = mle(model, input = 'data', n = 1, signal_process_groups = signal_shapes, with_covariance=True, with_error=True, ks = True, chi2 = True)

# the output is (fitted value, uncertainty)
# The first numbers in the brackets show how far we are from the nominal value (which is 0) after the fit. 
#A value of 1 would mean 1 sigma deviation. So we are below 1 sigma deviation. 
#The second numbers in the brackets illustrates the uncertainty on the fitted value, it should be below 1, 
#and a value close to 1 corresponds to "no sensitivity" on the systematic.

print ("Determine nuisance parameters and their uncertainties")
parameter_values = {}
parameter_uncert = {}
for p in model.get_parameters([]):
    parameter_values[p] = fit['ttbar'][p][0][0]
    parameter_uncert[p] = fit['ttbar'][p][0][1]
    
    print [p, "%.4f" %parameter_values[p], "%.4f" %parameter_uncert[p] ]



parameter_values['beta_signal'] =  res['ttbar'][0][0]


histos = evaluate_prediction(model, parameter_values, include_signal = True)
write_histograms_to_rootfile(histos, 'histos-mle_ttbar.root')

print ("------------------------------------------------------------------")
print ("------------------------------------------------------------------")

#############################################
#### Perform fit excluding one nuisance param
#############################################


if dosysttable:
	total_up = 0
	total_down = 0

	print ["Determine the impact of each systematic"]
	for p in model.get_parameters([]):
		model_syst = model.copy()
		model_syst.distribution.set_distribution_parameters(p, width = 0.0, mean = parameter_values[p], range = [parameter_values[p], parameter_values[p]])
		res_syst = pl_interval(model_syst, 'data', n=1, cls = [one_sigma], signal_process_groups = signal_shapes )
	
       		print [ p, "%.4f" %res_syst['ttbar'][0][0] , "%.4f" %res_syst['ttbar'][one_sigma][0][0] , "%.4f" %res_syst['ttbar'][one_sigma][0][1] ]
	
		syst_down_excluded   = res_syst['ttbar'][one_sigma][0][0]
        	syst_up_excluded     = res_syst['ttbar'][one_sigma][0][1]
	
		print ["syst contribution down/up", "%.4f" %( syst_down-syst_down_excluded), "%.4f" %(syst_up-syst_up_excluded)]
	
		total_up   = total_up   + (syst_down_excluded - syst_down)*(syst_down_excluded - syst_down)
		total_down = total_down + (syst_up-syst_up_excluded)*(syst_up-syst_up_excluded)
	
        	print ["--------------------------------"]

	print ["total syst down/up" ,"%.4f" % total_down**(0.5), "%.4f" %total_up**(0.5)]



print ("------------------------------------------------------------------")
print ("------------------------------------------------------------------")

################################
#### Perform toy MC
################################


if dobiasscan:
	for i in range(11):
		print ("perform toy MC for bias scan")
		fixed_dist = get_fixed_dist(model.distribution)
		#mle(model, "toys:1.0", 1000, nuisance_prior_toys = fixed_dist)
		print i
		if i==0:
			res_toy = pl_interval(model, 'toys:0.5', n=1000, cls = [one_sigma], signal_process_groups = signal_shapes, nuisance_prior_toys = fixed_dist )
		if i==1:
			res_toy = pl_interval(model, 'toys:0.6', n=1000, cls = [one_sigma], signal_process_groups = signal_shapes, nuisance_prior_toys = fixed_dist )
		if i==2:
			res_toy = pl_interval(model, 'toys:0.7', n=1000, cls = [one_sigma], signal_process_groups = signal_shapes, nuisance_prior_toys = fixed_dist )
		if i==3:
			res_toy = pl_interval(model, 'toys:0.8', n=1000, cls = [one_sigma], signal_process_groups = signal_shapes, nuisance_prior_toys = fixed_dist )
		if i==4:
			res_toy = pl_interval(model, 'toys:0.9', n=1000, cls = [one_sigma], signal_process_groups = signal_shapes, nuisance_prior_toys = fixed_dist )
		if i==5:
			res_toy = pl_interval(model, 'toys:1.0', n=1000, cls = [one_sigma], signal_process_groups = signal_shapes, nuisance_prior_toys = fixed_dist )
		if i==6:
			res_toy = pl_interval(model, 'toys:1.1', n=1000, cls = [one_sigma], signal_process_groups = signal_shapes, nuisance_prior_toys = fixed_dist )
		if i==7:
			res_toy = pl_interval(model, 'toys:1.2', n=1000, cls = [one_sigma], signal_process_groups = signal_shapes, nuisance_prior_toys = fixed_dist )
		if i==8:
			res_toy = pl_interval(model, 'toys:1.3', n=1000, cls = [one_sigma], signal_process_groups = signal_shapes, nuisance_prior_toys = fixed_dist )
		if i==9:
			res_toy = pl_interval(model, 'toys:1.4', n=1000, cls = [one_sigma], signal_process_groups = signal_shapes, nuisance_prior_toys = fixed_dist )
		if i==10:
			res_toy = pl_interval(model, 'toys:1.5', n=1000, cls = [one_sigma], signal_process_groups = signal_shapes, nuisance_prior_toys = fixed_dist )
		print [ "%.4f" %res_toy['ttbar'][0][0] , "%.4f" %res_toy['ttbar'][one_sigma][0][0] , "%.4f" %res_toy['ttbar'][one_sigma][0][1] ] 




report = model_summary(model)
#report.write_html('htmlout')
