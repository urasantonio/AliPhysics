#ifndef ALIDIMUINFOSTOREMC_H
#define ALIDIMUINFOSTOREMC_H

/* Copyright(c) 1998-2006, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

//***********************************************************
// Class AliDimuInfoStoreMC
// class used to extract and store info of MC particles
// Author: X-M. Zhang, zhang@clermont.in2p3.fr
//                     zhangxm@iopp.ccnu.edu.cn
//***********************************************************

#include <TLorentzVector.h>
#include "AliDimuInfoStoreRD.h"

class AliMuonInfoStoreMC;
class AliDimuInfoStoreMC : public AliDimuInfoStoreRD {
 public:

  AliDimuInfoStoreMC();
  AliDimuInfoStoreMC(AliMuonInfoStoreMC* const trk0, AliMuonInfoStoreMC* const trk1, Bool_t full=kFALSE);
  AliDimuInfoStoreMC(const AliDimuInfoStoreMC &src);
  AliDimuInfoStoreMC& operator=(const AliDimuInfoStoreMC &src);
  virtual ~AliDimuInfoStoreMC();

  AliMuonInfoStoreMC* Muon(Int_t i) const { return (i<2 ? (AliMuonInfoStoreMC*)(fMuonRef[i].GetObject()) : 0x0); }

  TLorentzVector LorentzP() const { return fLorentzP; }
  Int_t DimuSource() const { return fSource; }

  static const char* StdBranchName() { return fgkStdBranchName.Data(); }
  const static Int_t NSources()      { return fgkNSources;             }


 private:

  void FindDimuonSourceFast();
  void FindDimuonSourceFull();

  static const TString fgkStdBranchName;  // Standard branch name
  static const Int_t   fgkNSources;       // num. of dimuon sources

  Bool_t fIsFull;  // flag of using full analysis (for Pb-Pb)
  TLorentzVector fLorentzP;  // lorentz momentum of MC particle
  Int_t fSource;  // = 0, BBdiff
                  // = 1, Bchain
                  // = 2, DDdiff
                  // = 3, Dchain
                  // = 4, Resonance
                  // = 5, UnCorr bkg

  ClassDef(AliDimuInfoStoreMC, 1);
};

#endif
