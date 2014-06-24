
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



void CompareSystPlots(TString syst, TString process){
    
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasColor(0); // must be kWhite but I dunno how to do that in PyROOT  
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");

 
  //TFile * inputfile_fit = new TFile("RootFiles/Template_JES_JER_BTag_LES_Q2_Mpts_VVsplit.root");
  TFile * inputfile_fit = new TFile("RootFiles/TemplateNJetsNBjets_JES_JER_BTag_LES_Q2_Mpts_TopPt.root");

  TH1F * hist_NJetsNBjets__rare         = (TH1F*)inputfile_fit->Get( ("NJetsNBjets__"+process).Data() )->Clone();
  TH1F * hist_NJetsNBjets__rare__minus  = (TH1F*)inputfile_fit->Get( ("NJetsNBjets__"+process+"__"+syst+"__minus").Data() )->Clone();
  TH1F * hist_NJetsNBjets__rare__plus   = (TH1F*)inputfile_fit->Get( ("NJetsNBjets__"+process+"__"+syst+"__plus").Data() )->Clone();
  
  
  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);
  c1->cd();

  
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(1, "(0,0)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(2, "(1,0)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(3, "(1,1)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(4, "(2,0)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(5, "(2,1)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(6, "(2,2)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(7, "(3,0)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(8, "(3,1)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(9, "(3,2)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(10, "(3,3)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(11, "(4,0)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(12, "(4,1)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(13, "(4,2)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(14, "(4,3)");
  hist_NJetsNBjets__rare->GetXaxis()->SetBinLabel(14, "(4,>3)");
  hist_NJetsNBjets__rare->GetXaxis()->SetTitle("(NJets, NBJets)");
  hist_NJetsNBjets__rare->SetTitle("");
  
  
  hist_NJetsNBjets__rare->       SetLineColor(1);
  hist_NJetsNBjets__rare__minus->SetLineColor(2);
  hist_NJetsNBjets__rare__plus-> SetLineColor(4);
  
  
  hist_NJetsNBjets__rare->       SetLineWidth(3);
  hist_NJetsNBjets__rare__minus->SetLineWidth(3);
  hist_NJetsNBjets__rare__plus-> SetLineWidth(3);
  
  
  hist_NJetsNBjets__rare->Draw("LS");
  hist_NJetsNBjets__rare__minus->Draw("same");
  hist_NJetsNBjets__rare__plus->Draw("same");
  
   
  TLegend* qw = new TLegend(.45,.60,.85,.85);
  qw->SetShadowColor(0);
  qw->SetFillColor(0);
  qw->SetLineColor(0);
  qw->AddEntry(hist_NJetsNBjets__rare,          ("NJetsNBjets__"+process).Data() , "l");
  qw->AddEntry(hist_NJetsNBjets__rare__minus,   ("NJetsNBjets__"+process+"__"+syst+"__minus").Data()  , "l");
  qw->AddEntry(hist_NJetsNBjets__rare__plus,    ("NJetsNBjets__"+process+"__"+syst+"__plus").Data()  , "l");
 
  qw->Draw();
  c1->SaveAs( ("plots/NJetsNBjets__"+process+"__"+syst+".gif").Data());
}

void CompareSystPlots(){
  

  //for ttbar
  CompareSystPlots("jes",  "ttbar");
  CompareSystPlots("jer",  "ttbar");
  CompareSystPlots("btag", "ttbar");
  CompareSystPlots("les",  "ttbar");
  CompareSystPlots("q2",   "ttbar");
  CompareSystPlots("mpts", "ttbar");
  //CompareSystPlots("toppt", "ttbar");
  
  
  
  
  //for stop
  CompareSystPlots("jes",  "stop");
  CompareSystPlots("jer",  "stop");
  CompareSystPlots("btag", "stop");
  CompareSystPlots("les",  "stop");
  CompareSystPlots("q2",   "stop");
  CompareSystPlots("mpts", "stop");
  
  //for dy
  CompareSystPlots("jes",  "dy");
  CompareSystPlots("jer",  "dy");
  CompareSystPlots("btag", "dy");
  CompareSystPlots("les",  "dy");
  CompareSystPlots("q2",   "dy");
  CompareSystPlots("mpts", "dy");
  
  //for rare
  CompareSystPlots("jes",  "rare");
  CompareSystPlots("jer",  "rare");
  CompareSystPlots("btag", "rare");
  CompareSystPlots("les",  "rare");
  CompareSystPlots("q2",   "rare");
  CompareSystPlots("mpts", "rare");
  
  
  //for fake
  CompareSystPlots("jes",  "fake");
  CompareSystPlots("jer",  "fake");
  CompareSystPlots("btag", "fake");
  CompareSystPlots("les",  "fake");
  CompareSystPlots("q2",   "fake");
  CompareSystPlots("mpts", "fake");
  
  
  
}
