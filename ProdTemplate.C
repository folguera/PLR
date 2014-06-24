#include "TString.h"
#include "TH1F.h"
#include "TStyle.h"
#include "TFile.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "THStack.h"
#include <iostream>



void setNjetSel(TH1F * thehisto, int njetsel){
  
  if(njetsel!=0) {
    for(int i=1; i<=njetsel; i++){
      thehisto->SetBinContent(i, 0.0000000001);
      thehisto->SetBinError(i, 0.0000000001);
    }
  }
  
}


void ProdTemplate(TString inputdistrib, bool addJES, bool addJER, bool addBTag, bool addLES, bool addQ2, bool addMpts, bool addTopPt, bool splitVV,
TString outputfilename, int njetsel){
  
  
  TFile * inputfile       = new TFile("RootFiles/Jun22_Jet30_CSVM_TopPtLepSysMll_MC.root");
  
  
  
  TH1F * NJetsNBjets__DATA             = (TH1F*)inputfile->Get( (inputdistrib+"__DATA").Data() )->Clone();
  TH1F * NJetsNBjets__ttbar            = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar").Data() )->Clone();  
  TH1F * NJetsNBjets__stop             = (TH1F*)inputfile->Get( (inputdistrib+"__stop").Data() )->Clone();
  TH1F * NJetsNBjets__dy               = (TH1F*)inputfile->Get( (inputdistrib+"__dy").Data() )->Clone();
  TH1F * NJetsNBjets__rare             = (TH1F*)inputfile->Get( (inputdistrib+"__rare").Data() )->Clone();
  TH1F * NJetsNBjets__fake             = (TH1F*)inputfile->Get( (inputdistrib+"__fake").Data() )->Clone();
  
  
  TH1F * NJetsNBjets__vv ;
  TH1F * NJetsNBjets__ww ;
  TH1F * NJetsNBjets__zz ;
  TH1F * NJetsNBjets__wz ;
  
  
  
  if(!splitVV) NJetsNBjets__vv		= (TH1F*)inputfile->Get( (inputdistrib+"__vv").Data() )->Clone();
  else{
    NJetsNBjets__ww		= (TH1F*)inputfile->Get( (inputdistrib+"__ww").Data() )->Clone();
    NJetsNBjets__zz		= (TH1F*)inputfile->Get( (inputdistrib+"__zz").Data() )->Clone();
    NJetsNBjets__wz		= (TH1F*)inputfile->Get( (inputdistrib+"__wz").Data() )->Clone();
  }
  
  
  
  
  
  
  TH1F * NJetsNBjets__ttbar__jes__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__jes__plus").Data() )->Clone(); 
  TH1F * NJetsNBjets__stop__jes__plus    = (TH1F*)inputfile->Get( (inputdistrib+"__stop__jes__plus").Data() )->Clone();	
  TH1F * NJetsNBjets__dy__jes__plus      = (TH1F*)inputfile->Get( (inputdistrib+"__dy__jes__plus").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__jes__plus    = (TH1F*)inputfile->Get( (inputdistrib+"__rare__jes__plus").Data() )->Clone();	
  TH1F * NJetsNBjets__fake__jes__plus    = (TH1F*)inputfile->Get( (inputdistrib+"__fake__jes__plus").Data() )->Clone();
  	
  TH1F * NJetsNBjets__vv__jes__plus;	    
  TH1F * NJetsNBjets__ww__jes__plus;	    
  TH1F * NJetsNBjets__zz__jes__plus;	    
  TH1F * NJetsNBjets__wz__jes__plus;
  
  if(!splitVV) NJetsNBjets__vv__jes__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__vv__jes__plus").Data() )->Clone();
  else{	 
    NJetsNBjets__ww__jes__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__ww__jes__plus").Data() )->Clone();	 
    NJetsNBjets__zz__jes__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__zz__jes__plus").Data() )->Clone();	 
    NJetsNBjets__wz__jes__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__wz__jes__plus").Data() )->Clone();
  }	 
  
  TH1F * NJetsNBjets__ttbar__jes__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__jes__minus").Data() )->Clone(); 
  TH1F * NJetsNBjets__stop__jes__minus   = (TH1F*)inputfile->Get( (inputdistrib+"__stop__jes__minus").Data() )->Clone();  
  TH1F * NJetsNBjets__dy__jes__minus     = (TH1F*)inputfile->Get( (inputdistrib+"__dy__jes__minus").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__jes__minus   = (TH1F*)inputfile->Get( (inputdistrib+"__rare__jes__minus").Data() )->Clone();  
  TH1F * NJetsNBjets__fake__jes__minus   = (TH1F*)inputfile->Get( (inputdistrib+"__fake__jes__minus").Data() )->Clone();
  
  TH1F * NJetsNBjets__vv__jes__minus ;
  TH1F * NJetsNBjets__ww__jes__minus ;
  TH1F * NJetsNBjets__zz__jes__minus ;
  TH1F * NJetsNBjets__wz__jes__minus ;
  
  if(!splitVV) NJetsNBjets__vv__jes__minus	= (TH1F*)inputfile->Get( (inputdistrib+"__vv__jes__minus").Data() )->Clone();
  else{
    NJetsNBjets__ww__jes__minus	= (TH1F*)inputfile->Get( (inputdistrib+"__ww__jes__minus").Data() )->Clone();
    NJetsNBjets__zz__jes__minus	= (TH1F*)inputfile->Get( (inputdistrib+"__zz__jes__minus").Data() )->Clone();
    NJetsNBjets__wz__jes__minus	= (TH1F*)inputfile->Get( (inputdistrib+"__wz__jes__minus").Data() )->Clone();
  }
 
  
  
  TH1F * NJetsNBjets__ttbar__jer__plus         = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__jer").Data() )->Clone();       
  TH1F * NJetsNBjets__stop__jer__plus          = (TH1F*)inputfile->Get( (inputdistrib+"__stop__jer").Data() )->Clone();        
  TH1F * NJetsNBjets__dy__jer__plus            = (TH1F*)inputfile->Get( (inputdistrib+"__dy__jer").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__jer__plus          = (TH1F*)inputfile->Get( (inputdistrib+"__rare__jer").Data() )->Clone();        
  TH1F * NJetsNBjets__fake__jer__plus          = (TH1F*)inputfile->Get( (inputdistrib+"__fake__jer").Data() )->Clone();  
  
        
  TH1F * NJetsNBjets__vv__jer__plus;	      
  TH1F * NJetsNBjets__ww__jer__plus;	   
  TH1F * NJetsNBjets__zz__jer__plus;	
  TH1F * NJetsNBjets__wz__jer__plus;  
  
       
  if(!splitVV) NJetsNBjets__vv__jer__plus	      = (TH1F*)inputfile->Get( (inputdistrib+"__vv__jer").Data() )->Clone();
  else{	   
    NJetsNBjets__ww__jer__plus	      = (TH1F*)inputfile->Get( (inputdistrib+"__ww__jer").Data() )->Clone();	
    NJetsNBjets__zz__jer__plus	      = (TH1F*)inputfile->Get( (inputdistrib+"__zz__jer").Data() )->Clone();    
    NJetsNBjets__wz__jer__plus	      = (TH1F*)inputfile->Get( (inputdistrib+"__wz__jer").Data() )->Clone(); 
  }
  
  
  TH1F * NJetsNBjets__ttbar__jer__minus        = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar").Data() )->Clone(); 
  TH1F * NJetsNBjets__stop__jer__minus         = (TH1F*)inputfile->Get( (inputdistrib+"__stop").Data() )->Clone();   
  TH1F * NJetsNBjets__dy__jer__minus           = (TH1F*)inputfile->Get( (inputdistrib+"__dy").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__jer__minus         = (TH1F*)inputfile->Get( (inputdistrib+"__rare").Data() )->Clone(); 
  TH1F * NJetsNBjets__fake__jer__minus         = (TH1F*)inputfile->Get( (inputdistrib+"__fake").Data() )->Clone(); 
  
  TH1F * NJetsNBjets__vv__jer__minus; 
  TH1F * NJetsNBjets__ww__jer__minus; 
  TH1F * NJetsNBjets__zz__jer__minus; 
  TH1F * NJetsNBjets__wz__jer__minus; 
  
  if(!splitVV) NJetsNBjets__vv__jer__minus	      = (TH1F*)inputfile->Get( (inputdistrib+"__vv").Data() )->Clone(); 
  else{
    NJetsNBjets__ww__jer__minus	      = (TH1F*)inputfile->Get( (inputdistrib+"__ww").Data() )->Clone(); 
    NJetsNBjets__zz__jer__minus	      = (TH1F*)inputfile->Get( (inputdistrib+"__zz").Data() )->Clone(); 
    NJetsNBjets__wz__jer__minus	      = (TH1F*)inputfile->Get( (inputdistrib+"__wz").Data() )->Clone();
  } 
 
  
  
  
  TH1F * NJetsNBjets__ttbar__btag__plus  = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__btag__plus").Data() )->Clone(); 
  TH1F * NJetsNBjets__stop__btag__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__stop__btag__plus").Data() )->Clone();  
  TH1F * NJetsNBjets__dy__btag__plus     = (TH1F*)inputfile->Get( (inputdistrib+"__dy__btag__plus").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__btag__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__rare__btag__plus").Data() )->Clone();  
  TH1F * NJetsNBjets__fake__btag__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__fake__btag__plus").Data() )->Clone(); 
  
  TH1F * NJetsNBjets__vv__btag__plus; 
  TH1F * NJetsNBjets__ww__btag__plus; 
  TH1F * NJetsNBjets__zz__btag__plus; 
  TH1F * NJetsNBjets__wz__btag__plus;
   
  if(!splitVV) NJetsNBjets__vv__btag__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__vv__btag__plus").Data() )->Clone(); 
  else{
    NJetsNBjets__ww__btag__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__ww__btag__plus").Data() )->Clone(); 
    NJetsNBjets__zz__btag__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__zz__btag__plus").Data() )->Clone(); 
    NJetsNBjets__wz__btag__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__wz__btag__plus").Data() )->Clone(); 
  }
   
  TH1F * NJetsNBjets__ttbar__btag__minus = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__btag__minus").Data() )->Clone();      
  TH1F * NJetsNBjets__stop__btag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__stop__btag__minus").Data() )->Clone();       
  TH1F * NJetsNBjets__dy__btag__minus    = (TH1F*)inputfile->Get( (inputdistrib+"__dy__btag__minus").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__btag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__rare__btag__minus").Data() )->Clone(); 
  TH1F * NJetsNBjets__fake__btag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__fake__btag__minus").Data() )->Clone(); 
  
  TH1F * NJetsNBjets__vv__btag__minus; 
  TH1F * NJetsNBjets__ww__btag__minus; 
  TH1F * NJetsNBjets__zz__btag__minus; 
  TH1F * NJetsNBjets__wz__btag__minus; 
  
  if(!splitVV) NJetsNBjets__vv__btag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__vv__btag__minus").Data() )->Clone();
  else{ 
    NJetsNBjets__ww__btag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__ww__btag__minus").Data() )->Clone(); 
    NJetsNBjets__zz__btag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__zz__btag__minus").Data() )->Clone(); 
    NJetsNBjets__wz__btag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__wz__btag__minus").Data() )->Clone();
  }
  
  //---
   
  
  TH1F * NJetsNBjets__ttbar__mistag__plus  = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__mistag__plus").Data() )->Clone(); 
  TH1F * NJetsNBjets__stop__mistag__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__stop__mistag__plus").Data() )->Clone();  
  TH1F * NJetsNBjets__dy__mistag__plus     = (TH1F*)inputfile->Get( (inputdistrib+"__dy__mistag__plus").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__mistag__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__rare__mistag__plus").Data() )->Clone();  
  TH1F * NJetsNBjets__fake__mistag__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__fake__mistag__plus").Data() )->Clone(); 
  
  TH1F * NJetsNBjets__vv__mistag__plus; 
  TH1F * NJetsNBjets__ww__mistag__plus; 
  TH1F * NJetsNBjets__zz__mistag__plus; 
  TH1F * NJetsNBjets__wz__mistag__plus;
   
  if(!splitVV) NJetsNBjets__vv__mistag__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__vv__mistag__plus").Data() )->Clone(); 
  else{
    NJetsNBjets__ww__mistag__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__ww__mistag__plus").Data() )->Clone(); 
    NJetsNBjets__zz__mistag__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__zz__mistag__plus").Data() )->Clone(); 
    NJetsNBjets__wz__mistag__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__wz__mistag__plus").Data() )->Clone(); 
  }
   
  TH1F * NJetsNBjets__ttbar__mistag__minus = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__mistag__minus").Data() )->Clone();      
  TH1F * NJetsNBjets__stop__mistag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__stop__mistag__minus").Data() )->Clone();       
  TH1F * NJetsNBjets__dy__mistag__minus    = (TH1F*)inputfile->Get( (inputdistrib+"__dy__mistag__minus").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__mistag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__rare__mistag__minus").Data() )->Clone(); 
  TH1F * NJetsNBjets__fake__mistag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__fake__mistag__minus").Data() )->Clone(); 
  
  TH1F * NJetsNBjets__vv__mistag__minus; 
  TH1F * NJetsNBjets__ww__mistag__minus; 
  TH1F * NJetsNBjets__zz__mistag__minus; 
  TH1F * NJetsNBjets__wz__mistag__minus; 
  
  if(!splitVV) NJetsNBjets__vv__mistag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__vv__mistag__minus").Data() )->Clone();
  else{ 
    NJetsNBjets__ww__mistag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__ww__mistag__minus").Data() )->Clone(); 
    NJetsNBjets__zz__mistag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__zz__mistag__minus").Data() )->Clone(); 
    NJetsNBjets__wz__mistag__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__wz__mistag__minus").Data() )->Clone();
  }
  
  
  
  
  
  TH1F * NJetsNBjets__ttbar__les__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__les__plus").Data() )->Clone();  
  TH1F * NJetsNBjets__stop__les__plus    = (TH1F*)inputfile->Get( (inputdistrib+"__stop__les__plus").Data() )->Clone();	
  TH1F * NJetsNBjets__dy__les__plus      = (TH1F*)inputfile->Get( (inputdistrib+"__dy__les__plus").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__les__plus    = (TH1F*)inputfile->Get( (inputdistrib+"__rare__les__plus").Data() )->Clone();	
  TH1F * NJetsNBjets__fake__les__plus    = (TH1F*)inputfile->Get( (inputdistrib+"__fake__les__plus").Data() )->Clone();
  
  TH1F * NJetsNBjets__vv__les__plus;
  TH1F * NJetsNBjets__ww__les__plus;
  TH1F * NJetsNBjets__zz__les__plus;
  TH1F * NJetsNBjets__wz__les__plus;
  
  if(!splitVV) NJetsNBjets__vv__les__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__vv__les__plus").Data() )->Clone();
  else{
    NJetsNBjets__ww__les__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__ww__les__plus").Data() )->Clone();
    NJetsNBjets__zz__les__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__zz__les__plus").Data() )->Clone();
    NJetsNBjets__wz__les__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__wz__les__plus").Data() )->Clone();
  }
  
  TH1F * NJetsNBjets__ttbar__les__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__les__minus").Data() )->Clone(); 
  TH1F * NJetsNBjets__stop__les__minus   = (TH1F*)inputfile->Get( (inputdistrib+"__stop__les__minus").Data() )->Clone();  
  TH1F * NJetsNBjets__dy__les__minus     = (TH1F*)inputfile->Get( (inputdistrib+"__dy__les__minus").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__les__minus   = (TH1F*)inputfile->Get( (inputdistrib+"__rare__les__minus").Data() )->Clone();  
  TH1F * NJetsNBjets__fake__les__minus   = (TH1F*)inputfile->Get( (inputdistrib+"__fake__les__minus").Data() )->Clone(); 
  
  TH1F * NJetsNBjets__vv__les__minus; 
  TH1F * NJetsNBjets__ww__les__minus; 
  TH1F * NJetsNBjets__zz__les__minus; 
  TH1F * NJetsNBjets__wz__les__minus; 
  
  if(!splitVV) NJetsNBjets__vv__les__minus	= (TH1F*)inputfile->Get( (inputdistrib+"__vv__les__minus").Data() )->Clone();
  else{ 
    NJetsNBjets__ww__les__minus	= (TH1F*)inputfile->Get( (inputdistrib+"__ww__les__minus").Data() )->Clone(); 
    NJetsNBjets__zz__les__minus	= (TH1F*)inputfile->Get( (inputdistrib+"__zz__les__minus").Data() )->Clone(); 
    NJetsNBjets__wz__les__minus	= (TH1F*)inputfile->Get( (inputdistrib+"__wz__les__minus").Data() )->Clone(); 
  }
  
  
  TH1F * NJetsNBjets__ttbar__q2__plus    = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__q2__plus").Data() )->Clone();	
  TH1F * NJetsNBjets__stop__q2__plus     = (TH1F*)inputfile->Get( (inputdistrib+"__stop__q2__plus").Data() )->Clone();	
  TH1F * NJetsNBjets__dy__q2__plus       = (TH1F*)inputfile->Get( (inputdistrib+"__dy__q2__plus").Data() )->Clone();     
  TH1F * NJetsNBjets__rare__q2__plus     = (TH1F*)inputfile->Get( (inputdistrib+"__rare__q2__plus").Data() )->Clone();	
  TH1F * NJetsNBjets__fake__q2__plus     = (TH1F*)inputfile->Get( (inputdistrib+"__fake__q2__plus").Data() )->Clone();
  
  
  TH1F * NJetsNBjets__vv__q2__plus;
  TH1F * NJetsNBjets__ww__q2__plus;
  TH1F * NJetsNBjets__zz__q2__plus;
  TH1F * NJetsNBjets__wz__q2__plus;
  
  if(!splitVV) NJetsNBjets__vv__q2__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__vv__q2__plus").Data() )->Clone();
  else{
    NJetsNBjets__ww__q2__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__ww__q2__plus").Data() )->Clone();
    NJetsNBjets__zz__q2__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__zz__q2__plus").Data() )->Clone();
    NJetsNBjets__wz__q2__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__wz__q2__plus").Data() )->Clone();
  }
  	
  TH1F * NJetsNBjets__ttbar__q2__minus   = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__q2__minus").Data() )->Clone();  
  TH1F * NJetsNBjets__stop__q2__minus    = (TH1F*)inputfile->Get( (inputdistrib+"__stop__q2__minus").Data() )->Clone();	
  TH1F * NJetsNBjets__dy__q2__minus      = (TH1F*)inputfile->Get( (inputdistrib+"__dy__q2__minus").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__q2__minus    = (TH1F*)inputfile->Get( (inputdistrib+"__rare__q2__minus").Data() )->Clone();
  TH1F * NJetsNBjets__fake__q2__minus    = (TH1F*)inputfile->Get( (inputdistrib+"__fake__q2__minus").Data() )->Clone();
  
  TH1F * NJetsNBjets__vv__q2__minus;
  TH1F * NJetsNBjets__ww__q2__minus;
  TH1F * NJetsNBjets__zz__q2__minus;
  TH1F * NJetsNBjets__wz__q2__minus;
  
  
  if(!splitVV) NJetsNBjets__vv__q2__minus	= (TH1F*)inputfile->Get( (inputdistrib+"__vv__q2__minus").Data() )->Clone();
  else{
    NJetsNBjets__ww__q2__minus	= (TH1F*)inputfile->Get( (inputdistrib+"__ww__q2__minus").Data() )->Clone();
    NJetsNBjets__zz__q2__minus	= (TH1F*)inputfile->Get( (inputdistrib+"__zz__q2__minus").Data() )->Clone();
    NJetsNBjets__wz__q2__minus	= (TH1F*)inputfile->Get( (inputdistrib+"__wz__q2__minus").Data() )->Clone();
  }
  
  TH1F * NJetsNBjets__ttbar__mpts__plus  = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__mpts__plus").Data() )->Clone(); 
  TH1F * NJetsNBjets__stop__mpts__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__stop__mpts__plus").Data() )->Clone();  
  TH1F * NJetsNBjets__dy__mpts__plus     = (TH1F*)inputfile->Get( (inputdistrib+"__dy__mpts__plus").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__mpts__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__rare__mpts__plus").Data() )->Clone();  
  TH1F * NJetsNBjets__fake__mpts__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__fake__mpts__plus").Data() )->Clone(); 
  
  TH1F * NJetsNBjets__vv__mpts__plus; 
  TH1F * NJetsNBjets__ww__mpts__plus; 
  TH1F * NJetsNBjets__zz__mpts__plus; 
  TH1F * NJetsNBjets__wz__mpts__plus; 
  
  if(!splitVV) NJetsNBjets__vv__mpts__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__vv__mpts__plus").Data() )->Clone(); 
  else{
    NJetsNBjets__ww__mpts__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__ww__mpts__plus").Data() )->Clone(); 
    NJetsNBjets__zz__mpts__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__zz__mpts__plus").Data() )->Clone(); 
    NJetsNBjets__wz__mpts__plus	= (TH1F*)inputfile->Get( (inputdistrib+"__wz__mpts__plus").Data() )->Clone(); 
  }
   
  TH1F * NJetsNBjets__ttbar__mpts__minus = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__mpts__minus").Data() )->Clone();  
  TH1F * NJetsNBjets__stop__mpts__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__stop__mpts__minus").Data() )->Clone(); 
  TH1F * NJetsNBjets__dy__mpts__minus    = (TH1F*)inputfile->Get( (inputdistrib+"__dy__mpts__minus").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__mpts__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__rare__mpts__minus").Data() )->Clone(); 
  TH1F * NJetsNBjets__fake__mpts__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__fake__mpts__minus").Data() )->Clone(); 
  
  TH1F * NJetsNBjets__vv__mpts__minus ; 
  TH1F * NJetsNBjets__ww__mpts__minus ; 
  TH1F * NJetsNBjets__zz__mpts__minus ; 
  TH1F * NJetsNBjets__wz__mpts__minus ; 
  
  if(!splitVV) NJetsNBjets__vv__mpts__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__vv__mpts__minus").Data() )->Clone(); 
  else{
    NJetsNBjets__ww__mpts__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__ww__mpts__minus").Data() )->Clone(); 
    NJetsNBjets__zz__mpts__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__zz__mpts__minus").Data() )->Clone(); 
    NJetsNBjets__wz__mpts__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__wz__mpts__minus").Data() )->Clone(); 
  }
  
  TH1F * NJetsNBjets__ttbar__toppt__plus  = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__toppt__plus").Data() )->Clone(); 
  TH1F * NJetsNBjets__stop__toppt__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__stop__toppt__plus").Data() )->Clone();  
  TH1F * NJetsNBjets__dy__toppt__plus     = (TH1F*)inputfile->Get( (inputdistrib+"__dy__toppt__plus").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__toppt__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__rare__toppt__plus").Data() )->Clone();  
  TH1F * NJetsNBjets__fake__toppt__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__fake__toppt__plus").Data() )->Clone(); 
  
  TH1F * NJetsNBjets__vv__toppt__plus; 
  TH1F * NJetsNBjets__ww__toppt__plus; 
  TH1F * NJetsNBjets__zz__toppt__plus; 
  TH1F * NJetsNBjets__wz__toppt__plus; 
   
  
  if(!splitVV) NJetsNBjets__vv__toppt__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__vv__toppt__plus").Data() )->Clone(); 
  else{
    NJetsNBjets__ww__toppt__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__ww__toppt__plus").Data() )->Clone(); 
    NJetsNBjets__zz__toppt__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__zz__toppt__plus").Data() )->Clone(); 
    NJetsNBjets__wz__toppt__plus   = (TH1F*)inputfile->Get( (inputdistrib+"__wz__toppt__plus").Data() )->Clone(); 
  }
   
  TH1F * NJetsNBjets__ttbar__toppt__minus = (TH1F*)inputfile->Get( (inputdistrib+"__ttbar__toppt__minus").Data() )->Clone();  
  TH1F * NJetsNBjets__stop__toppt__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__stop__toppt__minus").Data() )->Clone(); 
  TH1F * NJetsNBjets__dy__toppt__minus    = (TH1F*)inputfile->Get( (inputdistrib+"__dy__toppt__minus").Data() )->Clone();	
  TH1F * NJetsNBjets__rare__toppt__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__rare__toppt__minus").Data() )->Clone(); 
  TH1F * NJetsNBjets__fake__toppt__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__fake__toppt__minus").Data() )->Clone(); 
  
  TH1F * NJetsNBjets__vv__toppt__minus; 
  TH1F * NJetsNBjets__ww__toppt__minus; 
  TH1F * NJetsNBjets__zz__toppt__minus; 
  TH1F * NJetsNBjets__wz__toppt__minus; 
  
  if(!splitVV) NJetsNBjets__vv__toppt__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__vv__toppt__minus").Data() )->Clone();
  else{ 
    NJetsNBjets__ww__toppt__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__ww__toppt__minus").Data() )->Clone(); 
    NJetsNBjets__zz__toppt__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__zz__toppt__minus").Data() )->Clone(); 
    NJetsNBjets__wz__toppt__minus  = (TH1F*)inputfile->Get( (inputdistrib+"__wz__toppt__minus").Data() )->Clone(); 
  }
  
  
  //bool addJES, bool addJER, bool addBTag, bool addLES, bool addQ2, bool addMpts
  if(addJES)   outputfilename+="_JES";
  if(addJER)   outputfilename+="_JER";
  if(addBTag)  outputfilename+="_BTag";
  if(addLES)   outputfilename+="_LES";
  if(addQ2)    outputfilename+="_Q2";
  if(addMpts)  outputfilename+="_Mpts";
  if(addTopPt) outputfilename+="_TopPt";
  if(splitVV)  outputfilename+="_VVsplit";
  outputfilename+=".root";
  
  TFile * outputfile = new TFile(outputfilename, "recreate" );
  outputfile->cd();
  
  setNjetSel(NJetsNBjets__DATA,   njetsel);  
  setNjetSel(NJetsNBjets__ttbar,  njetsel); 
  setNjetSel(NJetsNBjets__stop,   njetsel); 
  setNjetSel(NJetsNBjets__dy,     njetsel); 
  setNjetSel(NJetsNBjets__rare,   njetsel); 
  setNjetSel(NJetsNBjets__fake,   njetsel); 
  setNjetSel(NJetsNBjets__vv,   njetsel);
  setNjetSel(NJetsNBjets__ww,   njetsel);
  setNjetSel(NJetsNBjets__zz,   njetsel);
  setNjetSel(NJetsNBjets__wz,   njetsel);
  NJetsNBjets__DATA->Write();      
  NJetsNBjets__ttbar->Write(); 	      
  NJetsNBjets__stop->Write(); 	      
  NJetsNBjets__dy->Write();  	      
  NJetsNBjets__rare->Write(); 	      
  NJetsNBjets__fake->Write(); 	     
  if(!splitVV){
    NJetsNBjets__vv->Write(); 
  }else{	     
    NJetsNBjets__ww->Write(); 	    
    NJetsNBjets__zz->Write(); 	   
    NJetsNBjets__wz->Write(); 
  }	
  
  
  
  if(addJES){ 
    setNjetSel(NJetsNBjets__ttbar__jes__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__jes__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__jes__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__jes__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__jes__plus,   njetsel); 
    setNjetSel(NJetsNBjets__vv__jes__plus,   njetsel); 
    setNjetSel(NJetsNBjets__ww__jes__plus,   njetsel); 
    setNjetSel(NJetsNBjets__zz__jes__plus,   njetsel); 
    setNjetSel(NJetsNBjets__wz__jes__plus,   njetsel); 
    
    setNjetSel(NJetsNBjets__ttbar__jes__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__jes__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__jes__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__jes__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__jes__minus,  njetsel);  
    setNjetSel(NJetsNBjets__vv__jes__minus,  njetsel); 
    setNjetSel(NJetsNBjets__ww__jes__minus,  njetsel); 
    setNjetSel(NJetsNBjets__zz__jes__minus,  njetsel); 
    setNjetSel(NJetsNBjets__wz__jes__minus,  njetsel); 
    
    
    NJetsNBjets__ttbar__jes__plus->Write();  
    NJetsNBjets__stop__jes__plus ->Write();     
    NJetsNBjets__dy__jes__plus->Write();        
    NJetsNBjets__rare__jes__plus->Write();      
    NJetsNBjets__fake__jes__plus ->Write();      
    if(!splitVV){
      NJetsNBjets__vv__jes__plus ->Write(); 
    }else{	             
      NJetsNBjets__ww__jes__plus ->Write();        
      NJetsNBjets__zz__jes__plus ->Write();       
      NJetsNBjets__wz__jes__plus ->Write();    
    }
    NJetsNBjets__ttbar__jes__minus->Write();    
    NJetsNBjets__stop__jes__minus ->Write();    
    NJetsNBjets__dy__jes__minus->Write();       
    NJetsNBjets__rare__jes__minus->Write();     
    NJetsNBjets__fake__jes__minus->Write();     
    if(!splitVV){
      NJetsNBjets__vv__jes__minus->Write(); 
    }else{	           
      NJetsNBjets__ww__jes__minus->Write();      
      NJetsNBjets__zz__jes__minus->Write();     
      NJetsNBjets__wz__jes__minus->Write(); 
    }  
  }  
  if(addJER){    
    setNjetSel(NJetsNBjets__ttbar__jer__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__jer__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__jer__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__jer__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__jer__plus,   njetsel); 
    setNjetSel(NJetsNBjets__vv__jer__plus,   njetsel); 
    setNjetSel(NJetsNBjets__ww__jer__plus,   njetsel); 
    setNjetSel(NJetsNBjets__zz__jer__plus,   njetsel); 
    setNjetSel(NJetsNBjets__wz__jer__plus,   njetsel); 
    
    setNjetSel(NJetsNBjets__ttbar__jer__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__jer__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__jer__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__jer__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__jer__minus,  njetsel);  
    setNjetSel(NJetsNBjets__vv__jer__minus,  njetsel);  
    setNjetSel(NJetsNBjets__ww__jer__minus,  njetsel);  
    setNjetSel(NJetsNBjets__zz__jer__minus,  njetsel);  
    setNjetSel(NJetsNBjets__wz__jer__minus,  njetsel);  
    
    
    NJetsNBjets__ttbar__jer__plus->Write((inputdistrib+"__ttbar__jer__plus").Data() );     
    NJetsNBjets__stop__jer__plus->Write((inputdistrib+"__stop__jer__plus").Data() );      
    NJetsNBjets__dy__jer__plus->Write((inputdistrib+"__dy__jer__plus").Data() );        
    NJetsNBjets__rare__jer__plus->Write((inputdistrib+"__rare__jer__plus").Data() );      
    NJetsNBjets__fake__jer__plus->Write((inputdistrib+"__fake__jer__plus").Data() );        
    if(!splitVV){
      NJetsNBjets__vv__jer__plus->Write((inputdistrib+"__vv__jer__plus").Data() ); 
    }else{	                
      NJetsNBjets__ww__jer__plus->Write((inputdistrib+"__ww__jer__plus").Data() );          
      NJetsNBjets__zz__jer__plus->Write((inputdistrib+"__zz__jer__plus").Data() );        
      NJetsNBjets__wz__jer__plus->Write((inputdistrib+"__wz__jer__plus").Data() );    
    }
    NJetsNBjets__ttbar__jer__minus->Write((inputdistrib+"__ttbar__jer__minus").Data() );    
    NJetsNBjets__stop__jer__minus->Write((inputdistrib+"__stop__jer__minus").Data() );     
    NJetsNBjets__dy__jer__minus->Write((inputdistrib+"__dy__jer__minus").Data() );       
    NJetsNBjets__rare__jer__minus->Write((inputdistrib+"__rare__jer__minus").Data() );     
    NJetsNBjets__fake__jer__minus->Write((inputdistrib+"__fake__jer__minus").Data() );     
    if(!splitVV){
      NJetsNBjets__vv__jer__minus->Write((inputdistrib+"__vv__jer__minus").Data() );  
    }else{	            
      NJetsNBjets__ww__jer__minus->Write((inputdistrib+"__ww__jer__minus").Data() );       
      NJetsNBjets__zz__jer__minus->Write((inputdistrib+"__zz__jer__minus").Data() );     
      NJetsNBjets__wz__jer__minus->Write((inputdistrib+"__wz__jer__minus").Data() );
    }    
  }    
  if(addBTag){       
    setNjetSel(NJetsNBjets__ttbar__btag__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__btag__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__btag__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__btag__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__btag__plus,   njetsel);
    setNjetSel(NJetsNBjets__vv__btag__plus,   njetsel);
    setNjetSel(NJetsNBjets__ww__btag__plus,   njetsel);
    setNjetSel(NJetsNBjets__zz__btag__plus,   njetsel);
    setNjetSel(NJetsNBjets__wz__btag__plus,   njetsel);
     
    setNjetSel(NJetsNBjets__ttbar__btag__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__btag__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__btag__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__btag__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__btag__minus,  njetsel);  
    setNjetSel(NJetsNBjets__vv__btag__minus,  njetsel);
    setNjetSel(NJetsNBjets__ww__btag__minus,  njetsel);
    setNjetSel(NJetsNBjets__zz__btag__minus,  njetsel);
    setNjetSel(NJetsNBjets__wz__btag__minus,  njetsel);
  
  
    NJetsNBjets__ttbar__btag__plus->Write();    
    NJetsNBjets__stop__btag__plus->Write();     
    NJetsNBjets__dy__btag__plus->Write();       
    NJetsNBjets__rare__btag__plus->Write();     
    NJetsNBjets__fake__btag__plus->Write();   
    if(!splitVV){
      NJetsNBjets__vv__btag__plus->Write();
    }else{	     
      NJetsNBjets__ww__btag__plus->Write();
      NJetsNBjets__zz__btag__plus->Write();
      NJetsNBjets__wz__btag__plus->Write();
    }     
    NJetsNBjets__ttbar__btag__minus->Write();   
    NJetsNBjets__stop__btag__minus->Write();    
    NJetsNBjets__dy__btag__minus->Write();      
    NJetsNBjets__rare__btag__minus->Write();    
    NJetsNBjets__fake__btag__minus->Write();     
    if(!splitVV){
      NJetsNBjets__vv__btag__minus->Write(); 
    }else{	          
      NJetsNBjets__ww__btag__minus->Write();    
      NJetsNBjets__zz__btag__minus->Write();  
      NJetsNBjets__wz__btag__minus->Write(); 
    }    
    
      
    setNjetSel(NJetsNBjets__ttbar__mistag__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__mistag__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__mistag__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__mistag__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__mistag__plus,   njetsel);
    setNjetSel(NJetsNBjets__vv__mistag__plus,   njetsel);
    setNjetSel(NJetsNBjets__ww__mistag__plus,   njetsel);
    setNjetSel(NJetsNBjets__zz__mistag__plus,   njetsel);
    setNjetSel(NJetsNBjets__wz__mistag__plus,   njetsel);
     
    setNjetSel(NJetsNBjets__ttbar__mistag__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__mistag__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__mistag__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__mistag__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__mistag__minus,  njetsel);  
    setNjetSel(NJetsNBjets__vv__mistag__minus,  njetsel);
    setNjetSel(NJetsNBjets__ww__mistag__minus,  njetsel);
    setNjetSel(NJetsNBjets__zz__mistag__minus,  njetsel);
    setNjetSel(NJetsNBjets__wz__mistag__minus,  njetsel);
  
  
    NJetsNBjets__ttbar__mistag__plus->Write();    
    NJetsNBjets__stop__mistag__plus->Write();     
    NJetsNBjets__dy__mistag__plus->Write();       
    NJetsNBjets__rare__mistag__plus->Write();     
    NJetsNBjets__fake__mistag__plus->Write();   
    if(!splitVV){
      NJetsNBjets__vv__mistag__plus->Write();
    }else{	     
      NJetsNBjets__ww__mistag__plus->Write();
      NJetsNBjets__zz__mistag__plus->Write();
      NJetsNBjets__wz__mistag__plus->Write();
    }     
    NJetsNBjets__ttbar__mistag__minus->Write();   
    NJetsNBjets__stop__mistag__minus->Write();    
    NJetsNBjets__dy__mistag__minus->Write();      
    NJetsNBjets__rare__mistag__minus->Write();    
    NJetsNBjets__fake__mistag__minus->Write();     
    if(!splitVV){
      NJetsNBjets__vv__mistag__minus->Write(); 
    }else{	          
      NJetsNBjets__ww__mistag__minus->Write();    
      NJetsNBjets__zz__mistag__minus->Write();  
      NJetsNBjets__wz__mistag__minus->Write(); 
    } 
  }    
  if(addLES){     
    setNjetSel(NJetsNBjets__ttbar__les__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__les__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__les__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__les__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__les__plus,   njetsel); 
    setNjetSel(NJetsNBjets__vv__les__plus,   njetsel); 
    setNjetSel(NJetsNBjets__ww__les__plus,   njetsel); 
    setNjetSel(NJetsNBjets__zz__les__plus,   njetsel); 
    setNjetSel(NJetsNBjets__wz__les__plus,   njetsel); 
    
    setNjetSel(NJetsNBjets__ttbar__les__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__les__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__les__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__les__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__les__minus,  njetsel);  
    setNjetSel(NJetsNBjets__vv__les__minus,  njetsel);  
    setNjetSel(NJetsNBjets__ww__les__minus,  njetsel);  
    setNjetSel(NJetsNBjets__zz__les__minus,  njetsel);  
    setNjetSel(NJetsNBjets__wz__les__minus,  njetsel);  
    
    
    NJetsNBjets__ttbar__les__plus->Write();     
    NJetsNBjets__stop__les__plus->Write();      
    NJetsNBjets__dy__les__plus->Write();        
    NJetsNBjets__rare__les__plus->Write();      
    NJetsNBjets__fake__les__plus->Write();   
    if(!splitVV){
      NJetsNBjets__vv__les__plus->Write(); 
    }else{	        
      NJetsNBjets__ww__les__plus->Write(); 
      NJetsNBjets__zz__les__plus->Write(); 
      NJetsNBjets__wz__les__plus->Write(); 
    }  
    NJetsNBjets__ttbar__les__minus->Write();    
    NJetsNBjets__stop__les__minus->Write();     
    NJetsNBjets__dy__les__minus->Write();       
    NJetsNBjets__rare__les__minus->Write();     
    NJetsNBjets__fake__les__minus->Write();      
    if(!splitVV){
      NJetsNBjets__vv__les__minus->Write(); 
    }else{	           
      NJetsNBjets__ww__les__minus->Write();   
      NJetsNBjets__zz__les__minus->Write();  
      NJetsNBjets__wz__les__minus->Write();
    } 
    
  }      
  if(addQ2){   
    setNjetSel(NJetsNBjets__ttbar__q2__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__q2__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__q2__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__q2__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__q2__plus,   njetsel); 
    setNjetSel(NJetsNBjets__vv__q2__plus,   njetsel); 
    setNjetSel(NJetsNBjets__ww__q2__plus,   njetsel); 
    setNjetSel(NJetsNBjets__zz__q2__plus,   njetsel); 
    setNjetSel(NJetsNBjets__wz__q2__plus,   njetsel); 
    
    setNjetSel(NJetsNBjets__ttbar__q2__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__q2__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__q2__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__q2__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__q2__minus,  njetsel);  
    setNjetSel(NJetsNBjets__vv__q2__minus,  njetsel);   
    setNjetSel(NJetsNBjets__ww__q2__minus,  njetsel);   
    setNjetSel(NJetsNBjets__zz__q2__minus,  njetsel);   
    setNjetSel(NJetsNBjets__wz__q2__minus,  njetsel);   
     
    NJetsNBjets__ttbar__q2__plus->Write();      
    NJetsNBjets__stop__q2__plus->Write();	
    NJetsNBjets__dy__q2__plus->Write(); 	
    NJetsNBjets__rare__q2__plus->Write();	
    NJetsNBjets__fake__q2__plus->Write();	
    if(!splitVV){
      NJetsNBjets__vv__q2__plus->Write();
    }else{	     		
      NJetsNBjets__ww__q2__plus->Write();	
      NJetsNBjets__zz__q2__plus->Write();
      NJetsNBjets__wz__q2__plus->Write();
    }	
    NJetsNBjets__ttbar__q2__minus->Write();     
    NJetsNBjets__stop__q2__minus->Write();	
    NJetsNBjets__dy__q2__minus->Write();	
    NJetsNBjets__rare__q2__minus->Write();	
    NJetsNBjets__fake__q2__minus->Write();   	
    if(!splitVV){
      NJetsNBjets__vv__q2__minus->Write(); 
    }else{	         	
      NJetsNBjets__ww__q2__minus->Write();    	
      NJetsNBjets__zz__q2__minus->Write();   	
      NJetsNBjets__wz__q2__minus->Write(); 
    }  
    
  }      
  if(addMpts){ 
    setNjetSel(NJetsNBjets__ttbar__mpts__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__mpts__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__mpts__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__mpts__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__mpts__plus,   njetsel); 
    setNjetSel(NJetsNBjets__vv__mpts__plus,   njetsel); 
    setNjetSel(NJetsNBjets__ww__mpts__plus,   njetsel); 
    setNjetSel(NJetsNBjets__zz__mpts__plus,   njetsel); 
    setNjetSel(NJetsNBjets__wz__mpts__plus,   njetsel); 
    
    setNjetSel(NJetsNBjets__ttbar__mpts__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__mpts__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__mpts__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__mpts__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__mpts__minus,  njetsel);   
    setNjetSel(NJetsNBjets__vv__mpts__minus,  njetsel);     
    setNjetSel(NJetsNBjets__ww__mpts__minus,  njetsel);    
    setNjetSel(NJetsNBjets__zz__mpts__minus,  njetsel);   
    setNjetSel(NJetsNBjets__wz__mpts__minus,  njetsel);   
       
    NJetsNBjets__ttbar__mpts__plus->Write();    
    NJetsNBjets__stop__mpts__plus->Write();	
    NJetsNBjets__dy__mpts__plus->Write();	
    NJetsNBjets__rare__mpts__plus->Write();	
    NJetsNBjets__fake__mpts__plus->Write();
    if(!splitVV){
      NJetsNBjets__vv__mpts__plus->Write(); 
    }else{  
      NJetsNBjets__ww__mpts__plus->Write();
      NJetsNBjets__zz__mpts__plus->Write();
      NJetsNBjets__wz__mpts__plus->Write();
    }	
    NJetsNBjets__ttbar__mpts__minus->Write();   
    NJetsNBjets__stop__mpts__minus->Write();	
    NJetsNBjets__dy__mpts__minus->Write();	
    NJetsNBjets__rare__mpts__minus->Write();   
    NJetsNBjets__fake__mpts__minus->Write();	 
    if(!splitVV){
      NJetsNBjets__vv__mpts__minus->Write(); 
    }else{
      NJetsNBjets__ww__mpts__minus->Write();
      NJetsNBjets__zz__mpts__minus->Write();
      NJetsNBjets__wz__mpts__minus->Write();
    }
    
  }      
  if(addTopPt){ 
    setNjetSel(NJetsNBjets__ttbar__toppt__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__toppt__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__toppt__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__toppt__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__toppt__plus,   njetsel); 
    setNjetSel(NJetsNBjets__vv__toppt__plus,   njetsel); 
    setNjetSel(NJetsNBjets__ww__toppt__plus,   njetsel); 
    setNjetSel(NJetsNBjets__zz__toppt__plus,   njetsel); 
    setNjetSel(NJetsNBjets__wz__toppt__plus,   njetsel); 
    
    setNjetSel(NJetsNBjets__ttbar__toppt__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__toppt__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__toppt__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__toppt__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__toppt__minus,  njetsel);   
    setNjetSel(NJetsNBjets__vv__toppt__minus,  njetsel);     
    setNjetSel(NJetsNBjets__ww__toppt__minus,  njetsel);    
    setNjetSel(NJetsNBjets__zz__toppt__minus,  njetsel);   
    setNjetSel(NJetsNBjets__wz__toppt__minus,  njetsel);   
       
    NJetsNBjets__ttbar__toppt__plus->Write();    
    NJetsNBjets__stop__toppt__plus->Write();	
    NJetsNBjets__dy__toppt__plus->Write();	
    NJetsNBjets__rare__toppt__plus->Write();	
    NJetsNBjets__fake__toppt__plus->Write();
    if(!splitVV){
      NJetsNBjets__vv__toppt__plus->Write();
    }else{
      NJetsNBjets__ww__toppt__plus->Write();
      NJetsNBjets__zz__toppt__plus->Write();
      NJetsNBjets__wz__toppt__plus->Write();
    }	
    NJetsNBjets__ttbar__toppt__minus->Write();   
    NJetsNBjets__stop__toppt__minus->Write();	
    NJetsNBjets__dy__toppt__minus->Write();	
    NJetsNBjets__rare__toppt__minus->Write();   
    NJetsNBjets__fake__toppt__minus->Write();	 
    if(!splitVV){
      NJetsNBjets__vv__toppt__minus->Write();
    }else{		 
      NJetsNBjets__ww__toppt__minus->Write();	 
      NJetsNBjets__zz__toppt__minus->Write(); 
      NJetsNBjets__wz__toppt__minus->Write();
    }
    
  }
  
  outputfile->Close();
  inputfile->Close();
}



void ProdTemplate(){
  
  
 ProdTemplate("NJetsNBjets", true,        true,        true,         true,        true,        true,   true,   false, "RootFiles/TemplateNJetsNBjets", 0);
 ProdTemplate("InvMass",     true,        true,        true,         true,        true,        true,   true,   false, "RootFiles/TemplateInvMass", 0);

  
}
