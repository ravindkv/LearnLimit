// Full class description:
// https://root.cern.ch/doc/master/classRooRealVar.html

void learnRooFW(){
  //open the rooWorkspace file
  TFile *f  = new TFile("t2w_datacard_count.root");
  RooWorkspace * w = (RooWorkspace*) f->Get("w");

  //print the full content of w
  w->Print();

  //get the functions  
  RooAbsReal *fExp = w->function("n_exp_binCAT1");
  fExp->Print();

}
