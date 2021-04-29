//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <vector>
#include "MyApp.h"
#include "Candidate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TApp *App;
vector <Candidate> candidatesVector;
String arrayOption[2] = {"Add new one", "Edit by Id"};
String arraySex[2] = {"M", "F"};

void showMemos(TMemo *groomsMemo, TMemo *bridesMemo);
void loadFromFile(String file);

//---------------------------------------------------------------------------
__fastcall TApp::TApp(TComponent *Owner)
        : TForm(Owner) {
	bridesMemo->Clear();
	groomsMemo->Clear();
    optionComboBox->Items->Add(arrayOption[0]);
    optionComboBox->Items->Add(arrayOption[1]);
	sexComboBox->Items->Add(arraySex[0]);
	sexComboBox->Items->Add(arraySex[1]);
    //LOADING CANDIDATES
	loadFromFile("D:\\2_term_OAIP\\2Lab\\input.log");
	showMemos(groomsMemo, bridesMemo);
}

void showMemos(TMemo *groomsMemo, TMemo *bridesMemo) {
    bridesMemo->Clear();
    groomsMemo->Clear();
	for (int i = 0; i < candidatesVector.size(); i++) {
		if(candidatesVector[i].getIsFree()==true)
		{
			if (candidatesVector[i].getSex() == "M") {
				groomsMemo->Lines->Add("ID:"+IntToStr(i)+"   "+candidatesVector[i].getName()+" Age:"+candidatesVector[i].getAge()+" H:"+candidatesVector[i].getHeight()+" W:"+candidatesVector[i].getWeight());
				groomsMemo->Lines->Add(candidatesVector[i].getHobby()+" "+candidatesVector[i].getHabbit());
			} else {
				bridesMemo->Lines->Add("ID:"+IntToStr(i)+"   "+candidatesVector[i].getName()+" Age:"+candidatesVector[i].getAge()+" H:"+candidatesVector[i].getHeight()+" W:"+candidatesVector[i].getWeight());
				bridesMemo->Lines->Add(candidatesVector[i].getHobby()+" "+candidatesVector[i].getHabbit());
			}
        }

    }
}

//---------------------------------------------------------------------------
void __fastcall TApp::AddButtonClick(TObject *Sender) {
	if (optionComboBox->ItemIndex == 0) {
		try {
			Candidate tmp;
			tmp.setId(candidatesVector.size());
			tmp.setName(nameEdit->Text);
			tmp.setSex(arraySex[sexComboBox->ItemIndex]);
			tmp.setAge(StrToInt(ageEdit->Text));
			tmp.setHeight(StrToInt(heightEdit->Text));
			tmp.setWeight(StrToInt(weightEdit->Text));
			tmp.setHobby(hobbyEdit->Text);
			tmp.setHabbit(habbitEdit->Text);
			tmp.setMaxHeight(StrToInt(maxHeightEdit->Text));
			tmp.setMinHeight(StrToInt(minHeightEdit->Text));
			tmp.setMaxWeight(StrToInt(maxWeightEdit->Text));
			tmp.setMinWeight(StrToInt(minWeightEdit->Text));
			tmp.setMaxAge(StrToInt(maxAgeEdit->Text));
			tmp.setMinAge(StrToInt(minAgeEdit->Text));
			tmp.setIsFree(1);
			if (sexComboBox->ItemIndex == -1 || tmp.getMinHeight() > tmp.getMaxHeight() ||
				 tmp.getMinWeight() > tmp.getMaxWeight() || tmp.getMinAge() > tmp.getMaxAge())
				 {
				throw 1;
			}
			candidatesVector.push_back(tmp);
			idEdit->Enabled = true;
			idEdit->Text = candidatesVector.size();
			idEdit->Enabled = false;
		} catch (...) {}
	} else if (optionComboBox->ItemIndex == 1) {
		try {
			if (StrToInt(minHeightEdit->Text) > StrToInt(maxHeightEdit->Text) ||
				 StrToInt(minWeightEdit->Text) > StrToInt(maxWeightEdit->Text) || StrToInt(minAgeEdit->Text) > StrToInt(maxAgeEdit->Text))
			{
				throw 1;
			}
			candidatesVector[StrToInt(idEdit->Text)].setName(nameEdit->Text);
			candidatesVector[StrToInt(idEdit->Text)].setAge(StrToInt(ageEdit->Text));;
			candidatesVector[StrToInt(idEdit->Text)].setHeight(StrToInt(heightEdit->Text));
			candidatesVector[StrToInt(idEdit->Text)].setWeight(StrToInt(weightEdit->Text));
			candidatesVector[StrToInt(idEdit->Text)].setHobby(hobbyEdit->Text);
			candidatesVector[StrToInt(idEdit->Text)].setHabbit(habbitEdit->Text);
			candidatesVector[StrToInt(idEdit->Text)].setMaxHeight(StrToInt(maxHeightEdit->Text));
			candidatesVector[StrToInt(idEdit->Text)].setMinHeight(StrToInt(minHeightEdit->Text));
			candidatesVector[StrToInt(idEdit->Text)].setMaxWeight(StrToInt(maxWeightEdit->Text));
			candidatesVector[StrToInt(idEdit->Text)].setMinWeight(StrToInt(minWeightEdit->Text));
			candidatesVector[StrToInt(idEdit->Text)].setMaxAge(StrToInt(maxAgeEdit->Text));
			candidatesVector[StrToInt(idEdit->Text)].setMinAge(StrToInt(minAgeEdit->Text));
		}catch(...){}
	}
	showMemos(groomsMemo, bridesMemo);
}
//---------------------------------------------------------------------------


void __fastcall TApp::optionComboBoxChange(TObject *Sender) {
    idEdit->Clear();
	nameEdit->Clear();
	ageEdit->Clear();
	heightEdit->Clear();
	weightEdit->Clear();
	hobbyEdit->Clear();
	habbitEdit->Clear();
	maxHeightEdit->Clear();
	minHeightEdit->Clear();
	maxWeightEdit->Clear();
	minWeightEdit->Clear();
	maxAgeEdit->Clear();
	minAgeEdit->Clear();
    if (optionComboBox->ItemIndex == 0) {
        idEdit->Text = candidatesVector.size();
        idEdit->Enabled = false;
    } else {
        idEdit->Enabled = true;
    }

}
//---------------------------------------------------------------------------

void __fastcall TApp::idEditKeyPress(TObject *Sender, System::WideChar &Key) {
	if (Key == VK_RETURN && optionComboBox->ItemIndex == 1 && candidatesVector.size() > StrToInt(idEdit->Text) &&
		candidatesVector[StrToInt(idEdit->Text)].getIsFree() == true) {
		nameEdit->Text=candidatesVector[StrToInt(idEdit->Text)].getName();
		sexComboBox->Text=candidatesVector[StrToInt(idEdit->Text)].getSex();
		ageEdit->Text=candidatesVector[StrToInt(idEdit->Text)].getAge();
		heightEdit->Text=candidatesVector[StrToInt(idEdit->Text)].getHeight();
		weightEdit->Text=candidatesVector[StrToInt(idEdit->Text)].getWeight();
		hobbyEdit->Text=candidatesVector[StrToInt(idEdit->Text)].getHobby();
		habbitEdit->Text=candidatesVector[StrToInt(idEdit->Text)].getHabbit();
		maxHeightEdit->Text=candidatesVector[StrToInt(idEdit->Text)].getMaxHeight();
		minHeightEdit->Text=candidatesVector[StrToInt(idEdit->Text)].getMinHeight();
		maxWeightEdit->Text=candidatesVector[StrToInt(idEdit->Text)].getMaxWeight();
		minWeightEdit->Text=candidatesVector[StrToInt(idEdit->Text)].getMinWeight();
		maxAgeEdit->Text=candidatesVector[StrToInt(idEdit->Text)].getMaxAge();
		minAgeEdit->Text=candidatesVector[StrToInt(idEdit->Text)].getMinAge();
	}

}
//---------------------------------------------------------------------------

void __fastcall TApp::ShowButtonClick(TObject *Sender) {
	showMemos(groomsMemo, bridesMemo);
}
//---------------------------------------------------------------------------

void __fastcall TApp::SaveButtonClick(TObject *Sender) {
    if (FileExists("D:\\2_term_OAIP\\2Lab\\input.log")) {
        DeleteFile("D:\\2_term_OAIP\\2Lab\\input.log");
    }
    TFileStream *fp = new TFileStream("D:\\2_term_OAIP\\2Lab\\input.log", fmCreate);
	for (int i = 0; i < candidatesVector.size(); i++) {
		AnsiString str =candidatesVector[i].getName();
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
		str=candidatesVector[i].getSex();
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
		str=IntToStr(candidatesVector[i].getAge());
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
		str= IntToStr(candidatesVector[i].getHeight());
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
		str= IntToStr(candidatesVector[i].getWeight());
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
		str=candidatesVector[i].getHobby();
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
		str=candidatesVector[i].getHabbit();
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
		str=IntToStr(candidatesVector[i].getMaxHeight());
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
		str=IntToStr(candidatesVector[i].getMinHeight());
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
		str=IntToStr(candidatesVector[i].getMaxWeight());
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
		str=IntToStr(candidatesVector[i].getMinWeight());
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
        str=IntToStr(candidatesVector[i].getMaxAge());
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
		str=IntToStr(candidatesVector[i].getMinAge());
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
		str=IntToStr(candidatesVector[i].getIsFree());
		fp->Write(str.c_str(), str.Length());
		fp->Write("\n", 1);
    }
    delete fp;
}
//---------------------------------------------------------------------------

void __fastcall TApp::DeleteByIdButtonClick(TObject *Sender)
{
	try
	{
		if(StrToInt(DeletedIdEdit->Text)<candidatesVector.size())
		{
			candidatesVector[StrToInt(DeletedIdEdit->Text)].setIsFree(0);
			showMemos(groomsMemo, bridesMemo);
			if(DeletedIdEdit->Text==idEdit->Text)
				{
				idEdit->Clear();
				nameEdit->Clear();
				ageEdit->Clear();
				heightEdit->Clear();
				weightEdit->Clear();
				hobbyEdit->Clear();
				habbitEdit->Clear();
				maxHeightEdit->Clear();
				minHeightEdit->Clear();
				maxWeightEdit->Clear();
				minWeightEdit->Clear();
				maxAgeEdit->Clear();
				minAgeEdit->Clear();
				}
		}
        DeletedIdEdit->Clear();
	}catch(...){}
}
//---------------------------------------------------------------------------

bool isPair(Candidate &i,Candidate &j)
{
	 if(i.getAge()<=j.getMaxAge() && i.getAge()>=j.getMinAge() && i.getHeight()<=j.getMaxHeight() && i.getHeight()>=j.getMinHeight() &&
	 i.getWeight()<=j.getMaxWeight() && i.getWeight()>=j.getMinWeight() && i.getSex()!=j.getSex())
	 {
		return 1;
	 }else
	 {
		 return 0;
	 }
}

void findPairs(TMemo *groomsMemo,TMemo *bridesMemo)
{
    bridesMemo->Clear();
	groomsMemo->Clear();
	for(int i=0;i<candidatesVector.size()-1;i++)
	{
		for(int j=i+1;j<candidatesVector.size();j++)
		{
			if(candidatesVector[i].getIsFree() && candidatesVector[j].getIsFree() && isPair(candidatesVector[i], candidatesVector[j]) && isPair(candidatesVector[j], candidatesVector[i]))
			{
				 if(candidatesVector[i].getSex()=="M")
				 {
					groomsMemo->Lines->Add("ID: "+IntToStr(i)+" "+candidatesVector[i].getName());
					 bridesMemo->Lines->Add("ID: "+IntToStr(j)+" "+candidatesVector[j].getName());
				 }else
				 {
					 groomsMemo->Lines->Add("ID: "+IntToStr(j)+" "+candidatesVector[j].getName());
					 bridesMemo->Lines->Add("ID: "+IntToStr(i)+" "+candidatesVector[i].getName());
				 }
			}
		}
	}
}

void __fastcall TApp::pairsButtonClick(TObject *Sender)
{
	 findPairs(groomsMemo,bridesMemo);
}
//---------------------------------------------------------------------------


void __fastcall TApp::makePairButtonClick(TObject *Sender)
{
	try
	{
	   if(isPair(candidatesVector[StrToInt(Id1Edit->Text)], candidatesVector[StrToInt(Id2Edit->Text)]) && isPair(candidatesVector[StrToInt(Id2Edit->Text)], candidatesVector[StrToInt(Id1Edit->Text)]))
			{
				 candidatesVector[StrToInt(Id1Edit->Text)].setIsFree(0);
				 candidatesVector[StrToInt(Id2Edit->Text)].setIsFree(0);
				 Id1Edit->Clear();
                 Id2Edit->Clear();
                 findPairs(groomsMemo,bridesMemo);
			}
	}catch(...){}
}
//---------------------------------------------------------------------------

void __fastcall TApp::OpenButtonClick(TObject *Sender)
{
   TOpenDialog* OpenDialog = new TOpenDialog(App);
	OpenDialog->Filter = "(*.log; *.txt)|*.LOG;*.TXT";
	OpenDialog->InitialDir = "D:\\2_term_OAIP\\2Lab";
	if (OpenDialog->Execute()) {
		loadFromFile(OpenDialog->FileName);
		showMemos(groomsMemo, bridesMemo);
	}
	delete OpenDialog;
}
//---------------------------------------------------------------------------

void loadFromFile(String file)
{
	candidatesVector.clear();
    TStringList *List = new TStringList;
	try {
		List->LoadFromFile(file);
		int n=14;
		for (int i = 0; i <= List->Count / n; i++) {
            Candidate tmp;
			tmp.setId(candidatesVector.size());
			tmp.setName(List->Strings[i * n]);
			tmp.setSex(List->Strings[i * n + 1]);
			tmp.setAge(StrToInt(List->Strings[i * n + 2]));
			tmp.setHeight(StrToInt(List->Strings[i * n + 3]));
			tmp.setWeight(StrToInt(List->Strings[i * n + 4]));
			tmp.setHobby(List->Strings[i * n + 5]);
			tmp.setHabbit(List->Strings[i * n + 6]);
			tmp.setMaxHeight(StrToInt(List->Strings[i * n + 7]));
			tmp.setMinHeight(StrToInt(List->Strings[i * n + 8]));
			tmp.setMaxWeight(StrToInt(List->Strings[i * n + 9]));
			tmp.setMinWeight(StrToInt(List->Strings[i * n + 10]));
			tmp.setMaxAge(StrToInt(List->Strings[i * n + 11]));
			tmp.setMinAge(StrToInt(List->Strings[i * n + 12]));
			tmp.setIsFree(StrToInt(List->Strings[i * n + 13]));
			candidatesVector.push_back(tmp);
		}
	}
	catch (...) {}
	delete List;

}
