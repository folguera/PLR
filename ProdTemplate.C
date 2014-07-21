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


void ProdTemplate(TString inputdistrib, std::vector<TString> sampleList, std::vector<TString> stytList, TString intputfilename, TString outputfilename){
  
  TFile * inputfile	  = new TFile( intputfilename.Data() );

  TH1F * distrib__DATA  	   = (TH1F*)inputfile->Get( (inputdistrib+"__DATA").Data() )->Clone();
  
cout << __LINE__ << endl;
  
  std::vector<TH1F* > distrib_MC;
  std::vector<TH1F* > distrib_MC_sys;
  std::vector<TH1F* > distrib_MC_sys_jer_plus;
  std::vector<TH1F* > distrib_MC_sys_jer_minus;
  
cout << __LINE__ << endl;
  for(unsigned int i=0; i<sampleList.size(); i++){ 
    cout << inputdistrib+"__"+sampleList[i]  << endl;
    distrib_MC.push_back( (TH1F*)inputfile->Get( (inputdistrib+"__"+sampleList[i]).Data() )->Clone() ); 
  } 
  
  
cout << __LINE__ << endl;
  for(unsigned int i=0; i<sampleList.size(); i++){
    for(unsigned int j=0; j<stytList.size(); j++){
      if(stytList[j] != "jer") {
	distrib_MC_sys.push_back( (TH1F*)inputfile->Get( (inputdistrib+"__"+sampleList[i]+"__"+stytList[j]+"__plus").Data() )->Clone() );  
	distrib_MC_sys.push_back( (TH1F*)inputfile->Get( (inputdistrib+"__"+sampleList[i]+"__"+stytList[j]+"__minus").Data() )->Clone() );  
      }
    }
  }  
  
  
cout << __LINE__ << endl;
  for(unsigned int i=0; i<sampleList.size(); i++){
    distrib_MC_sys_jer_plus.push_back(  (TH1F*)inputfile->Get( (inputdistrib+"__"+sampleList[i]+"__jer").Data() )->Clone() ); 
    distrib_MC_sys_jer_minus.push_back( (TH1F*)inputfile->Get( (inputdistrib+"__"+sampleList[i]).Data() )->Clone() );	
  }

cout << __LINE__ << endl;
   
  for(unsigned int i=0; i<stytList.size(); i++) outputfilename+="_"+stytList[i];
  outputfilename+=".root"; 
  
  
cout << __LINE__ << endl;
  TFile * outputfile = new TFile(outputfilename, "recreate" );
  outputfile->cd();

  distrib__DATA->Write(); 
  
  
cout << __LINE__ << endl;
  for(unsigned int i=0; i<distrib_MC.size(); i++)               distrib_MC[i]->Write();
  for(unsigned int i=0; i<distrib_MC_sys.size(); i++)           distrib_MC_sys[i]->Write();
  for(unsigned int i=0; i<distrib_MC_sys_jer_plus.size();  i++) distrib_MC_sys_jer_plus[i]-> Write( (inputdistrib+"__"+sampleList[i]+"__jer__plus"). Data() );
  for(unsigned int i=0; i<distrib_MC_sys_jer_minus.size(); i++) distrib_MC_sys_jer_minus[i]->Write( (inputdistrib+"__"+sampleList[i]+"__jer__minus").Data() );
  
 
cout << __LINE__ << endl;
}


void ProdTemplate(){
  
  std::vector<TString> sampleList;
  sampleList.push_back("ttbar");
  sampleList.push_back("stop");
  sampleList.push_back("dy");
  sampleList.push_back("rare");
  sampleList.push_back("fake");
  sampleList.push_back("vv");
  
  
  std::vector<TString> systList;
  systList.push_back("jes");
  systList.push_back("jer");
  systList.push_back("btag");
  systList.push_back("mistag");
  systList.push_back("les");
  systList.push_back("q2");
  systList.push_back("mpts");
  systList.push_back("toppt");
  
  //ProdTemplate("NJetsNBjets", sampleList,  systList,  "RootFiles/Jun22_Jet30_CSVM_TopPtLepSysMll_MC.root", "test1");
  ProdTemplate("NJetsNBjets", sampleList,  systList,  "RootFiles/Jun22_Jet30_CSVL_TopPtLepSysMll_DD.root", "test1");
  
  
}
