#include "TCanvas.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TH2.h"
#include "TH3.h"
#include "TMath.h"
#include <iostream>

Int_t xnum = 6;
Int_t xmin = 0;
Int_t xmax = 6;

Int_t ynum = 6;
Int_t ymin = 0;
Int_t ymax = 6;

Int_t znum = 4000;
Int_t zmin = 0;
Int_t zmax = 8000;

TH2F * hRpdChannels;
TH2F * h2RPD;
TH3F * h3RPD;
TFile * tfin;
TDirectory * tdin;

void ThreeDhistos() {
    
    double chan01 = 0.;
    double chan02 = 0.;
    double chan03 = 0.;
    double chan04 = 0.;
    double chan05 = 0.;
    double chan06 = 0.;
    double chan07 = 0.;
    double chan08 = 0.;
    double chan09 = 0.;
    double chan10 = 0.;
    double chan11 = 0.;
    double chan12 = 0.;
    double chan13 = 0.;
    double chan14 = 0.;
    double chan15 = 0.;
    double chan16 = 0.;
    
    tfin = new TFile("DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO.root","read");
    
    hRpdChannels = (TH2F*)tfin->FindObjectAny("ZDC ERPD vs Channel");
    h2RPD = new TH2F("h2RPD","h2RPD",xnum,xmin,xmax,ynum,ymin,ymax);
    h3RPD = new TH3F("h3RPD","h3RPD",xnum,xmin,xmax,ynum,ymin,ymax,znum,zmin,zmax);
    h2RPD->Sumw2();
    h3RPD->Sumw2();
    h2RPD->SetOption("colz");
    
    for (int z=zmin+1; z<zmax+1; z++) {
        
        chan01+=hRpdChannels->GetBinContent(z,1);
        chan02+=hRpdChannels->GetBinContent(z,2);
        chan03+=hRpdChannels->GetBinContent(z,3);
        chan04+=hRpdChannels->GetBinContent(z,4);
        chan05+=hRpdChannels->GetBinContent(z,5);
        chan06+=hRpdChannels->GetBinContent(z,6);
        chan07+=hRpdChannels->GetBinContent(z,7);
        chan08+=hRpdChannels->GetBinContent(z,8);
        chan09+=hRpdChannels->GetBinContent(z,9);
        chan10+=hRpdChannels->GetBinContent(z,10);
        chan11+=hRpdChannels->GetBinContent(z,11);
        chan12+=hRpdChannels->GetBinContent(z,12);
        chan13+=hRpdChannels->GetBinContent(z,13);
        chan14+=hRpdChannels->GetBinContent(z,14);
        chan15+=hRpdChannels->GetBinContent(z,15);
        chan16+=hRpdChannels->GetBinContent(z,16);
        
        
        h3RPD->SetBinContent(5,5,z,hRpdChannels->GetBinContent(z,1));
        h3RPD->SetBinContent(4,5,z,hRpdChannels->GetBinContent(z,2));
        h3RPD->SetBinContent(3,5,z,hRpdChannels->GetBinContent(z,3));
        h3RPD->SetBinContent(2,5,z,hRpdChannels->GetBinContent(z,4));
        
        h3RPD->SetBinContent(5,4,z,hRpdChannels->GetBinContent(z,5));
        h3RPD->SetBinContent(4,4,z,hRpdChannels->GetBinContent(z,6));
        h3RPD->SetBinContent(3,4,z,hRpdChannels->GetBinContent(z,7));
        h3RPD->SetBinContent(2,4,z,hRpdChannels->GetBinContent(z,8));
        
        h3RPD->SetBinContent(5,3,z,hRpdChannels->GetBinContent(z,9));
        h3RPD->SetBinContent(4,3,z,hRpdChannels->GetBinContent(z,10));
        h3RPD->SetBinContent(3,3,z,hRpdChannels->GetBinContent(z,11));
        h3RPD->SetBinContent(2,3,z,hRpdChannels->GetBinContent(z,12));
        
        h3RPD->SetBinContent(5,2,z,hRpdChannels->GetBinContent(z,13));
        h3RPD->SetBinContent(4,2,z,hRpdChannels->GetBinContent(z,14));
        h3RPD->SetBinContent(3,2,z,hRpdChannels->GetBinContent(z,15));
        h3RPD->SetBinContent(2,2,z,hRpdChannels->GetBinContent(z,16));
        
        
        h3RPD->SetBinError(5,5,z,hRpdChannels->GetBinError(z,1));
        h3RPD->SetBinError(4,5,z,hRpdChannels->GetBinError(z,2));
        h3RPD->SetBinError(3,5,z,hRpdChannels->GetBinError(z,3));
        h3RPD->SetBinError(2,5,z,hRpdChannels->GetBinError(z,4));
        
        h3RPD->SetBinError(5,4,z,hRpdChannels->GetBinError(z,5));
        h3RPD->SetBinError(4,4,z,hRpdChannels->GetBinError(z,6));
        h3RPD->SetBinError(3,4,z,hRpdChannels->GetBinError(z,7));
        h3RPD->SetBinError(2,4,z,hRpdChannels->GetBinError(z,8));
        
        h3RPD->SetBinError(5,3,z,hRpdChannels->GetBinError(z,9));
        h3RPD->SetBinError(4,3,z,hRpdChannels->GetBinError(z,10));
        h3RPD->SetBinError(3,3,z,hRpdChannels->GetBinError(z,11));
        h3RPD->SetBinError(2,3,z,hRpdChannels->GetBinError(z,12));
        
        h3RPD->SetBinError(5,2,z,hRpdChannels->GetBinError(z,13));
        h3RPD->SetBinError(4,2,z,hRpdChannels->GetBinError(z,14));
        h3RPD->SetBinError(3,2,z,hRpdChannels->GetBinError(z,15));
        h3RPD->SetBinError(2,2,z,hRpdChannels->GetBinError(z,16));
    }
    
    h2RPD->SetBinContent(5,5,chan01);
    h2RPD->SetBinContent(4,5,chan02);
    h2RPD->SetBinContent(3,5,chan03);
    h2RPD->SetBinContent(2,5,chan04);
    
    h2RPD->SetBinContent(5,4,chan05);
    h2RPD->SetBinContent(4,4,chan06);
    h2RPD->SetBinContent(3,4,chan07);
    h2RPD->SetBinContent(2,4,chan08);
    
    h2RPD->SetBinContent(5,3,chan09);
    h2RPD->SetBinContent(4,3,chan10);
    h2RPD->SetBinContent(3,3,chan11);
    h2RPD->SetBinContent(2,3,chan12);
    
    h2RPD->SetBinContent(5,2,chan13);
    h2RPD->SetBinContent(4,2,chan14);
    h2RPD->SetBinContent(3,2,chan15);
    h2RPD->SetBinContent(2,2,chan16);
    
    TCanvas * c2RPD = new TCanvas("c2RPD","c2RPD",800,700);
    c2RPD->cd();
    h2RPD->Draw();
    
    TCanvas * c3RPD = new TCanvas("c3RPD","c3RPD",800,700);
    c3RPD->cd();
    h3RPD->GetZaxis()->SetRangeUser(0,200);
    h3RPD->Draw();
//    h3RPD->SetShowProjection("yx box");
}
