/*
 * $Id: main.cpp,v 1.8 2005/02/16 10:45:39 tsuruoka Exp $
 */

#include <stdio.h>
#include <fstream>
#include <map>
#include <list>
#include <iostream>
#include <sstream>
#include "maxent.h"
#include "common.h"

#include <cstdlib>

using namespace std;

string bidir_postag(const string & s, const vector<ME_Model> & vme, const vector<ME_Model> & cvme, bool dont_tokenize);
void bidir_chunking(vector<Sentence> & vs, const vector<ME_Model> & vme);
void init_morphdic();
void bidir_pos_train(string filename,int para);

void help()
{
  cout << "Usage: geniatagger [OPTION]... [FILE]..." << endl;
  cout << "Analyze English sentences and print the base forms, part-of-speech tags, " << endl;
  cout << "chunk tags, and named entity tags." << endl;
  cout << endl;
  cout << "Options:" << endl;
  cout << "  -nt          don't perform tokenization." << endl;
  cout << "  --help       display this help and exit." << endl;
  cout << endl;
  cout << "Report bugs to <tsuruoka@is.s.u-tokyo.ac.jp>." << endl;
}

void version()
{
  cout << "GENIA Tagger 3.0" << endl << endl;
}

extern void load_ne_models();

int main(int argc, char** argv)
{
  #if 0
  bool dont_tokenize = false;

  init_morphdic();

  vector<ME_Model> vme(16);

  cerr << "loading pos_models";
  for (int i = 0; i < 16; i++) {
    char buf[1000];
    sprintf(buf, "./models_medline/model.bidir.%d", i);
    vme[i].load_from_file(buf);
    cerr << ".";
  }
  cerr << "done." << endl;

  cerr << "loading chunk_models";
  vector<ME_Model> vme_chunking(16);
  for (int i = 0; i < 8; i +=2 ) {
    char buf[1000];
    sprintf(buf, "./models_chunking/model.bidir.%d", i);
    vme_chunking[i].load_from_file(buf);
    cerr << ".";
  }
  cerr << "done." << endl;

/*
  load_ne_models();
*/
  string line = "I am a good boy!";
  string postagged = bidir_postag(line, vme, vme_chunking, dont_tokenize);
  cout << postagged << endl;

  #endif

  string filename = "train.pos.cikuu";
  int para = -1;
  bidir_pos_train(filename,para);

  return 0;
}


