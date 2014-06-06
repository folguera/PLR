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


void ProdTemplate(bool addJES, bool addJER, bool addBTag, bool addLES, bool addQ2, bool addMpts, TString outputfilename, int njetsel){
  
  TFile * inputfile       = new TFile("RootFiles/HistosForHL_DD.root");
  
  
  
  TH1F * NJetsNBjets__DATA             = (TH1F*)inputfile->Get( "NJetsNBjets__DATA" )->Clone();
  TH1F * NJetsNBjets__ttbar            = (TH1F*)inputfile->Get( "NJetsNBjets__ttbar" )->Clone();  
  TH1F * NJetsNBjets__stop             = (TH1F*)inputfile->Get( "NJetsNBjets__stop" )->Clone();
  TH1F * NJetsNBjets__dy               = (TH1F*)inputfile->Get( "NJetsNBjets__dy" )->Clone();
  TH1F * NJetsNBjets__rare             = (TH1F*)inputfile->Get( "NJetsNBjets__rare" )->Clone();
  TH1F * NJetsNBjets__fake             = (TH1F*)inputfile->Get( "NJetsNBjets__fake" )->Clone();
  TH1F * NJetsNBjets__vv             = (TH1F*)inputfile->Get( "NJetsNBjets__vv" )->Clone();
  
  
  
  
  
  TH1F * NJetsNBjets__ttbar__jes__plus   = (TH1F*)inputfile->Get( "NJetsNBjets__ttbar__jes__plus" )->Clone(); 
  TH1F * NJetsNBjets__stop__jes__plus    = (TH1F*)inputfile->Get( "NJetsNBjets__stop__jes__plus" )->Clone();	
  TH1F * NJetsNBjets__dy__jes__plus      = (TH1F*)inputfile->Get( "NJetsNBjets__dy__jes__plus" )->Clone();	
  TH1F * NJetsNBjets__rare__jes__plus    = (TH1F*)inputfile->Get( "NJetsNBjets__rare__jes__plus" )->Clone();	
  TH1F * NJetsNBjets__fake__jes__plus    = (TH1F*)inputfile->Get( "NJetsNBjets__fake__jes__plus" )->Clone();	
  TH1F * NJetsNBjets__vv__jes__plus    = (TH1F*)inputfile->Get( "NJetsNBjets__vv__jes__plus" )->Clone();	
  
  TH1F * NJetsNBjets__ttbar__jes__minus  = (TH1F*)inputfile->Get( "NJetsNBjets__ttbar__jes__minus" )->Clone(); 
  TH1F * NJetsNBjets__stop__jes__minus   = (TH1F*)inputfile->Get( "NJetsNBjets__stop__jes__minus" )->Clone();  
  TH1F * NJetsNBjets__dy__jes__minus     = (TH1F*)inputfile->Get( "NJetsNBjets__dy__jes__minus" )->Clone();	
  TH1F * NJetsNBjets__rare__jes__minus   = (TH1F*)inputfile->Get( "NJetsNBjets__rare__jes__minus" )->Clone();  
  TH1F * NJetsNBjets__fake__jes__minus   = (TH1F*)inputfile->Get( "NJetsNBjets__fake__jes__minus" )->Clone();
  TH1F * NJetsNBjets__vv__jes__minus   = (TH1F*)inputfile->Get( "NJetsNBjets__vv__jes__minus" )->Clone();
 
  
  
  TH1F * NJetsNBjets__ttbar__jer__plus         = (TH1F*)inputfile->Get( "NJetsNBjets__ttbar__jer" )->Clone();       
  TH1F * NJetsNBjets__stop__jer__plus          = (TH1F*)inputfile->Get( "NJetsNBjets__stop__jer" )->Clone();        
  TH1F * NJetsNBjets__dy__jer__plus            = (TH1F*)inputfile->Get( "NJetsNBjets__dy__jer" )->Clone();	
  TH1F * NJetsNBjets__rare__jer__plus          = (TH1F*)inputfile->Get( "NJetsNBjets__rare__jer" )->Clone();        
  TH1F * NJetsNBjets__fake__jer__plus          = (TH1F*)inputfile->Get( "NJetsNBjets__fake__jer" )->Clone();        
  TH1F * NJetsNBjets__vv__jer__plus          = (TH1F*)inputfile->Get( "NJetsNBjets__vv__jer" )->Clone(); 
  
  
  TH1F * NJetsNBjets__ttbar__jer__minus        = (TH1F*)inputfile->Get( "NJetsNBjets__ttbar" )->Clone(); 
  TH1F * NJetsNBjets__stop__jer__minus         = (TH1F*)inputfile->Get( "NJetsNBjets__stop" )->Clone();   
  TH1F * NJetsNBjets__dy__jer__minus           = (TH1F*)inputfile->Get( "NJetsNBjets__dy" )->Clone();	
  TH1F * NJetsNBjets__rare__jer__minus         = (TH1F*)inputfile->Get( "NJetsNBjets__rare" )->Clone(); 
  TH1F * NJetsNBjets__fake__jer__minus         = (TH1F*)inputfile->Get( "NJetsNBjets__fake" )->Clone(); 
  TH1F * NJetsNBjets__vv__jer__minus         = (TH1F*)inputfile->Get( "NJetsNBjets__vv" )->Clone(); 
 
  
  
  TH1F * NJetsNBjets__ttbar__btag__plus  = (TH1F*)inputfile->Get( "NJetsNBjets__ttbar__btag__plus" )->Clone(); 
  TH1F * NJetsNBjets__stop__btag__plus   = (TH1F*)inputfile->Get( "NJetsNBjets__stop__btag__plus" )->Clone();  
  TH1F * NJetsNBjets__dy__btag__plus     = (TH1F*)inputfile->Get( "NJetsNBjets__dy__btag__plus" )->Clone();	
  TH1F * NJetsNBjets__rare__btag__plus   = (TH1F*)inputfile->Get( "NJetsNBjets__rare__btag__plus" )->Clone();  
  TH1F * NJetsNBjets__fake__btag__plus   = (TH1F*)inputfile->Get( "NJetsNBjets__fake__btag__plus" )->Clone(); 
  TH1F * NJetsNBjets__vv__btag__plus   = (TH1F*)inputfile->Get( "NJetsNBjets__vv__btag__plus" )->Clone(); 
   
  TH1F * NJetsNBjets__ttbar__btag__minus = (TH1F*)inputfile->Get( "NJetsNBjets__ttbar__btag__minus" )->Clone();      
  TH1F * NJetsNBjets__stop__btag__minus  = (TH1F*)inputfile->Get( "NJetsNBjets__stop__btag__minus" )->Clone();       
  TH1F * NJetsNBjets__dy__btag__minus    = (TH1F*)inputfile->Get( "NJetsNBjets__dy__btag__minus" )->Clone();	
  TH1F * NJetsNBjets__rare__btag__minus  = (TH1F*)inputfile->Get( "NJetsNBjets__rare__btag__minus" )->Clone(); 
  TH1F * NJetsNBjets__fake__btag__minus  = (TH1F*)inputfile->Get( "NJetsNBjets__fake__btag__minus" )->Clone(); 
  TH1F * NJetsNBjets__vv__btag__minus  = (TH1F*)inputfile->Get( "NJetsNBjets__vv__btag__minus" )->Clone(); 
  
  
  
  TH1F * NJetsNBjets__ttbar__les__plus   = (TH1F*)inputfile->Get( "NJetsNBjets__ttbar__les__plus" )->Clone();  
  TH1F * NJetsNBjets__stop__les__plus    = (TH1F*)inputfile->Get( "NJetsNBjets__stop__les__plus" )->Clone();	
  TH1F * NJetsNBjets__dy__les__plus      = (TH1F*)inputfile->Get( "NJetsNBjets__dy__les__plus" )->Clone();	
  TH1F * NJetsNBjets__rare__les__plus    = (TH1F*)inputfile->Get( "NJetsNBjets__rare__les__plus" )->Clone();	
  TH1F * NJetsNBjets__fake__les__plus    = (TH1F*)inputfile->Get( "NJetsNBjets__fake__les__plus" )->Clone();
  TH1F * NJetsNBjets__vv__les__plus    = (TH1F*)inputfile->Get( "NJetsNBjets__vv__les__plus" )->Clone();
  
  TH1F * NJetsNBjets__ttbar__les__minus  = (TH1F*)inputfile->Get( "NJetsNBjets__ttbar__les__minus" )->Clone(); 
  TH1F * NJetsNBjets__stop__les__minus   = (TH1F*)inputfile->Get( "NJetsNBjets__stop__les__minus" )->Clone();  
  TH1F * NJetsNBjets__dy__les__minus     = (TH1F*)inputfile->Get( "NJetsNBjets__dy__les__minus" )->Clone();	
  TH1F * NJetsNBjets__rare__les__minus   = (TH1F*)inputfile->Get( "NJetsNBjets__rare__les__minus" )->Clone();  
  TH1F * NJetsNBjets__fake__les__minus   = (TH1F*)inputfile->Get( "NJetsNBjets__fake__les__minus" )->Clone(); 
  TH1F * NJetsNBjets__vv__les__minus   = (TH1F*)inputfile->Get( "NJetsNBjets__vv__les__minus" )->Clone(); 
  
  
  TH1F * NJetsNBjets__ttbar__q2__plus    = (TH1F*)inputfile->Get( "NJetsNBjets__ttbar__q2__plus" )->Clone();	
  TH1F * NJetsNBjets__stop__q2__plus     = (TH1F*)inputfile->Get( "NJetsNBjets__stop__q2__plus" )->Clone();	
  TH1F * NJetsNBjets__dy__q2__plus       = (TH1F*)inputfile->Get( "NJetsNBjets__dy__q2__plus" )->Clone();     
  TH1F * NJetsNBjets__rare__q2__plus     = (TH1F*)inputfile->Get( "NJetsNBjets__rare__q2__plus" )->Clone();	
  TH1F * NJetsNBjets__fake__q2__plus     = (TH1F*)inputfile->Get( "NJetsNBjets__fake__q2__plus" )->Clone();
  TH1F * NJetsNBjets__vv__q2__plus     = (TH1F*)inputfile->Get( "NJetsNBjets__vv__q2__plus" )->Clone();
  	
  TH1F * NJetsNBjets__ttbar__q2__minus   = (TH1F*)inputfile->Get( "NJetsNBjets__ttbar__q2__minus" )->Clone();  
  TH1F * NJetsNBjets__stop__q2__minus    = (TH1F*)inputfile->Get( "NJetsNBjets__stop__q2__minus" )->Clone();	
  TH1F * NJetsNBjets__dy__q2__minus      = (TH1F*)inputfile->Get( "NJetsNBjets__dy__q2__minus" )->Clone();	
  TH1F * NJetsNBjets__rare__q2__minus    = (TH1F*)inputfile->Get( "NJetsNBjets__rare__q2__minus" )->Clone();
  TH1F * NJetsNBjets__fake__q2__minus    = (TH1F*)inputfile->Get( "NJetsNBjets__fake__q2__minus" )->Clone();
  TH1F * NJetsNBjets__vv__q2__minus    = (TH1F*)inputfile->Get( "NJetsNBjets__vv__q2__minus" )->Clone();
  
  
  TH1F * NJetsNBjets__ttbar__mpts__plus  = (TH1F*)inputfile->Get( "NJetsNBjets__ttbar__mpts__plus" )->Clone(); 
  TH1F * NJetsNBjets__stop__mpts__plus   = (TH1F*)inputfile->Get( "NJetsNBjets__stop__mpts__plus" )->Clone();  
  TH1F * NJetsNBjets__dy__mpts__plus     = (TH1F*)inputfile->Get( "NJetsNBjets__dy__mpts__plus" )->Clone();	
  TH1F * NJetsNBjets__rare__mpts__plus   = (TH1F*)inputfile->Get( "NJetsNBjets__rare__mpts__plus" )->Clone();  
  TH1F * NJetsNBjets__fake__mpts__plus   = (TH1F*)inputfile->Get( "NJetsNBjets__fake__mpts__plus" )->Clone(); 
  TH1F * NJetsNBjets__vv__mpts__plus   = (TH1F*)inputfile->Get( "NJetsNBjets__vv__mpts__plus" )->Clone(); 
   
  TH1F * NJetsNBjets__ttbar__mpts__minus = (TH1F*)inputfile->Get( "NJetsNBjets__ttbar__mpts__minus" )->Clone();  
  TH1F * NJetsNBjets__stop__mpts__minus  = (TH1F*)inputfile->Get( "NJetsNBjets__stop__mpts__minus" )->Clone(); 
  TH1F * NJetsNBjets__dy__mpts__minus    = (TH1F*)inputfile->Get( "NJetsNBjets__dy__mpts__minus" )->Clone();	
  TH1F * NJetsNBjets__rare__mpts__minus  = (TH1F*)inputfile->Get( "NJetsNBjets__rare__mpts__minus" )->Clone(); 
  TH1F * NJetsNBjets__fake__mpts__minus  = (TH1F*)inputfile->Get( "NJetsNBjets__fake__mpts__minus" )->Clone(); 
  TH1F * NJetsNBjets__vv__mpts__minus  = (TH1F*)inputfile->Get( "NJetsNBjets__vv__mpts__minus" )->Clone(); 
  
  
  //bool addJES, bool addJER, bool addBTag, bool addLES, bool addQ2, bool addMpts
  if(addJES)  outputfilename+="_JES";
  if(addJER)  outputfilename+="_JER";
  if(addBTag) outputfilename+="_BTag";
  if(addLES)  outputfilename+="_LES";
  if(addQ2)   outputfilename+="_Q2";
  if(addMpts) outputfilename+="_Mpts";
  
  outputfilename+=".root";
  
  TFile * outputfile = new TFile(outputfilename, "recreate");
  outputfile->cd();
  
  setNjetSel(NJetsNBjets__DATA,   njetsel);  
  setNjetSel(NJetsNBjets__ttbar,  njetsel); 
  setNjetSel(NJetsNBjets__stop,   njetsel); 
  setNjetSel(NJetsNBjets__dy,     njetsel); 
  setNjetSel(NJetsNBjets__rare,   njetsel); 
  setNjetSel(NJetsNBjets__fake,   njetsel); 
  setNjetSel(NJetsNBjets__vv,   njetsel);
  NJetsNBjets__DATA->Write();      
  NJetsNBjets__ttbar->Write(); 	      
  NJetsNBjets__stop->Write(); 	      
  NJetsNBjets__dy->Write();  	      
  NJetsNBjets__rare->Write(); 	      
  NJetsNBjets__fake->Write(); 	     
  NJetsNBjets__vv->Write(); 	
  
  
  
  if(addJES){ 
    setNjetSel(NJetsNBjets__ttbar__jes__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__jes__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__jes__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__jes__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__jes__plus,   njetsel); 
    setNjetSel(NJetsNBjets__vv__jes__plus,   njetsel); 
    
    setNjetSel(NJetsNBjets__ttbar__jes__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__jes__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__jes__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__jes__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__jes__minus,  njetsel);  
    setNjetSel(NJetsNBjets__vv__jes__minus,  njetsel); 
    
    NJetsNBjets__ttbar__jes__plus->Write();  
    NJetsNBjets__stop__jes__plus ->Write();     
    NJetsNBjets__dy__jes__plus->Write();        
    NJetsNBjets__rare__jes__plus->Write();      
    NJetsNBjets__fake__jes__plus ->Write();      
    NJetsNBjets__vv__jes__plus ->Write();    
    
    NJetsNBjets__ttbar__jes__minus->Write();    
    NJetsNBjets__stop__jes__minus ->Write();    
    NJetsNBjets__dy__jes__minus->Write();       
    NJetsNBjets__rare__jes__minus->Write();     
    NJetsNBjets__fake__jes__minus->Write();     
    NJetsNBjets__vv__jes__minus->Write();   
  }  
  if(addJER){    
    setNjetSel(NJetsNBjets__ttbar__jer__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__jer__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__jer__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__jer__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__jer__plus,   njetsel); 
    setNjetSel(NJetsNBjets__vv__jer__plus,   njetsel); 
    
    setNjetSel(NJetsNBjets__ttbar__jer__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__jer__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__jer__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__jer__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__jer__minus,  njetsel);  
    setNjetSel(NJetsNBjets__vv__jer__minus,  njetsel);  
    
    NJetsNBjets__ttbar__jer__plus->Write("NJetsNBjets__ttbar__jer__plus");     
    NJetsNBjets__stop__jer__plus->Write("NJetsNBjets__stop__jer__plus");      
    NJetsNBjets__dy__jer__plus->Write("NJetsNBjets__dy__jer__plus");        
    NJetsNBjets__rare__jer__plus->Write("NJetsNBjets__rare__jer__plus");      
    NJetsNBjets__fake__jer__plus->Write("NJetsNBjets__fake__jer__plus");        
    NJetsNBjets__vv__jer__plus->Write("NJetsNBjets__vv__jer__plus");    
    
    NJetsNBjets__ttbar__jer__minus->Write("NJetsNBjets__ttbar__jer__minus");    
    NJetsNBjets__stop__jer__minus->Write("NJetsNBjets__stop__jer__minus");     
    NJetsNBjets__dy__jer__minus->Write("NJetsNBjets__dy__jer__minus");       
    NJetsNBjets__rare__jer__minus->Write("NJetsNBjets__rare__jer__minus");     
    NJetsNBjets__fake__jer__minus->Write("NJetsNBjets__fake__jer__minus");     
    NJetsNBjets__vv__jer__minus->Write("NJetsNBjets__vv__jer__minus");    
  }    
  if(addBTag){       
    setNjetSel(NJetsNBjets__ttbar__btag__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__btag__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__btag__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__btag__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__btag__plus,   njetsel);
    setNjetSel(NJetsNBjets__vv__btag__plus,   njetsel);
     
    setNjetSel(NJetsNBjets__ttbar__btag__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__btag__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__btag__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__btag__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__btag__minus,  njetsel);  
    setNjetSel(NJetsNBjets__vv__btag__minus,  njetsel);
  
    NJetsNBjets__ttbar__btag__plus->Write();    
    NJetsNBjets__stop__btag__plus->Write();     
    NJetsNBjets__dy__btag__plus->Write();       
    NJetsNBjets__rare__btag__plus->Write();     
    NJetsNBjets__fake__btag__plus->Write();   
    NJetsNBjets__vv__btag__plus->Write();
         
    NJetsNBjets__ttbar__btag__minus->Write();   
    NJetsNBjets__stop__btag__minus->Write();    
    NJetsNBjets__dy__btag__minus->Write();      
    NJetsNBjets__rare__btag__minus->Write();    
    NJetsNBjets__fake__btag__minus->Write();     
    NJetsNBjets__vv__btag__minus->Write();  
  }    
  if(addLES){     
    setNjetSel(NJetsNBjets__ttbar__les__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__les__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__les__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__les__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__les__plus,   njetsel); 
    setNjetSel(NJetsNBjets__vv__les__plus,   njetsel); 
    
    setNjetSel(NJetsNBjets__ttbar__les__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__les__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__les__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__les__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__les__minus,  njetsel);  
    setNjetSel(NJetsNBjets__vv__les__minus,  njetsel);  
    
    NJetsNBjets__ttbar__les__plus->Write();     
    NJetsNBjets__stop__les__plus->Write();      
    NJetsNBjets__dy__les__plus->Write();        
    NJetsNBjets__rare__les__plus->Write();      
    NJetsNBjets__fake__les__plus->Write();   
    NJetsNBjets__vv__les__plus->Write(); 
         
    NJetsNBjets__ttbar__les__minus->Write();    
    NJetsNBjets__stop__les__minus->Write();     
    NJetsNBjets__dy__les__minus->Write();       
    NJetsNBjets__rare__les__minus->Write();     
    NJetsNBjets__fake__les__minus->Write();      
    NJetsNBjets__vv__les__minus->Write();  
  }      
  if(addQ2){   
    setNjetSel(NJetsNBjets__ttbar__q2__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__q2__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__q2__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__q2__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__q2__plus,   njetsel); 
    setNjetSel(NJetsNBjets__vv__q2__plus,   njetsel); 
    
    setNjetSel(NJetsNBjets__ttbar__q2__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__q2__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__q2__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__q2__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__q2__minus,  njetsel);  
    setNjetSel(NJetsNBjets__vv__q2__minus,  njetsel);   
     
    NJetsNBjets__ttbar__q2__plus->Write();      
    NJetsNBjets__stop__q2__plus->Write();	
    NJetsNBjets__dy__q2__plus->Write(); 	
    NJetsNBjets__rare__q2__plus->Write();	
    NJetsNBjets__fake__q2__plus->Write();	
    NJetsNBjets__vv__q2__plus->Write();
    	
    NJetsNBjets__ttbar__q2__minus->Write();     
    NJetsNBjets__stop__q2__minus->Write();	
    NJetsNBjets__dy__q2__minus->Write();	
    NJetsNBjets__rare__q2__minus->Write();	
    NJetsNBjets__fake__q2__minus->Write();   	
    NJetsNBjets__vv__q2__minus->Write();   
  }      
  if(addMpts){ 
    setNjetSel(NJetsNBjets__ttbar__mpts__plus,  njetsel);  
    setNjetSel(NJetsNBjets__stop__mpts__plus,   njetsel); 
    setNjetSel(NJetsNBjets__dy__mpts__plus,     njetsel); 
    setNjetSel(NJetsNBjets__rare__mpts__plus,   njetsel); 
    setNjetSel(NJetsNBjets__fake__mpts__plus,   njetsel); 
    setNjetSel(NJetsNBjets__vv__mpts__plus,   njetsel); 
    
    setNjetSel(NJetsNBjets__ttbar__mpts__minus, njetsel); 
    setNjetSel(NJetsNBjets__stop__mpts__minus,  njetsel); 
    setNjetSel(NJetsNBjets__dy__mpts__minus,    njetsel); 
    setNjetSel(NJetsNBjets__rare__mpts__minus,  njetsel); 
    setNjetSel(NJetsNBjets__fake__mpts__minus,  njetsel);   
    setNjetSel(NJetsNBjets__vv__mpts__minus,  njetsel);   
       
    NJetsNBjets__ttbar__mpts__plus->Write();    
    NJetsNBjets__stop__mpts__plus->Write();	
    NJetsNBjets__dy__mpts__plus->Write();	
    NJetsNBjets__rare__mpts__plus->Write();	
    NJetsNBjets__fake__mpts__plus->Write();
    NJetsNBjets__vv__mpts__plus->Write();
    	
    NJetsNBjets__ttbar__mpts__minus->Write();   
    NJetsNBjets__stop__mpts__minus->Write();	
    NJetsNBjets__dy__mpts__minus->Write();	
    NJetsNBjets__rare__mpts__minus->Write();   
    NJetsNBjets__fake__mpts__minus->Write();	 
    NJetsNBjets__vv__mpts__minus->Write();
  }
  
  outputfile->Close();
  inputfile->Close();
}



void ProdTemplate(){
  
 //ProdTemplate(bool addJES, bool addJER, bool addBTag, bool addLES, bool addQ2, bool addMpts, TString outputfilename)
   ProdTemplate(true,        true,        true,         true,        true,        true,  "RootFiles/Template", 0);
   //ProdTemplate(false, true,  true,  true,  true,  true,  "RootFiles/Template", 0);
   //ProdTemplate(true,  false, true,  true,  true,  true,  "RootFiles/Template", 0);
   //ProdTemplate(true,  true,  false, true,  true,  true,  "RootFiles/Template", 0);
   //ProdTemplate(true,  true,  true,  false, true,  true,  "RootFiles/Template", 0);
   //ProdTemplate(true,  true,  true,  true,  false, true,  "RootFiles/Template", 0);
   //ProdTemplate(true,  true,  true,  true,  true,  false, "RootFiles/Template", 0);

  
}
