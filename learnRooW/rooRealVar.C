// Full class description:
// https://root.cern.ch/doc/master/classRooRealVar.html

void rooRealVar(){
  //open the rooWorkspace file
  TFile *f  = new TFile("t2w_datacard_count.root");
  RooWorkspace * w = (RooWorkspace*) f->Get("w");

  //print the full content of w
  w->Print();

  //get the variable names 
  RooRealVar * nExp = w->var("n_exp_binCAT1_proc_ttbar");
  RooRealVar * nObs = w->var("n_obs_binCAT1");
  RooRealVar *sig = w->var("r");
  nExp->Print();
  nObs->Print();
  sig->Print();


  //print the value and error of the variable
  cout<<"nObs->getVal() = "<<nObs->getVal()<<endl;
  cout<<"nObs->getError() = "<<nObs->getError()<<endl;
  cout<<"nExp->getVal() = "<<nExp->getVal()<<endl;
  cout<<"nExp->getError() = "<<nExp->getError()<<endl;
  cout<<"sig->getVal() = "<<sig->getVal()<<endl;
  cout<<"sig->getError() = "<<sig->getError()<<endl;

  //create an empty histogram
  TH1F * hist_nObs = nObs->createHistogram( "nObs", "nObs", 0, 100, 10);
  hist_nObs->Draw();
}
