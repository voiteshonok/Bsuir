//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#include <cctype>
#pragma hdrstop
#include "Stack.h"
#include "App.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
double a,b,c,d,e;
int getPriority(char ch)
{
	switch(ch)
	{
		case '(':return 1;
		case '/':
		case '*':return 4;
		case '+':
		case '-':return 2;
	}
}

double getValue(char ch)
{
	switch(ch)
	{
		case 'a':return a;
		case 'b':return b;
		case 'c':return c;
		case 'd':return d;
		case 'e':return e;
        default:throw 1;
	}
}

void solve(AnsiString s,TListBox *result)
{
	Stack<double> *st = new Stack<double>;
	try
	{
		int len=strlen(s.c_str());
	   for(int i=1;i<=len;i++)
	   {
		   if(isalpha(s[i]))
		   {
			   st->add(getValue(s[i]));
		   }else
		   {
				double x= st->top();
				st->pop();
				double y=st->top();
                st->pop();
				switch(s[i])
				{
					case '+':st->add(x+y);break;
					case '-':st->add(y-x);break;
					case '*':st->add(y*x);break;
					case '/':st->add(y/x);break;
					default:throw 1;
				}
		   }
	   }
	   result->Items->Add(st->top());
	}catch(...)
	{
		result->Items->Add("invalid input");
	}
	delete st;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CulculateButtonClick(TObject *Sender)
{
   result->Clear();
   postForm-> Clear();
   Stack<char> *stPost = new Stack<char>;
	Stack<char> *stCh = new Stack<char>;
	AnsiString str = InfEdit->Text;
	int len = strlen(str.c_str());
	try{
    for(int i=1;i<=len;i++)
    {
        if(isalpha(str[i]))
        {
			stPost->add((double)str[i]);
        }else
        {
            if(str[i]=='(')
            {
				stCh->add((double)'(');
            }else if(str[i]==')')
            {
                while(stCh->top()!='(')
                {
					stPost->add(stCh->top());
                    stCh->pop();
                }
				stCh->pop();
            }else
            {
				while(stCh->notEmpty() && getPriority((char)stCh->top())>=getPriority((char)str[i]))
                {
					stPost->add(stCh->top());
					stCh->pop();
                }
				stCh->add((double)str[i]);
            }
		}
    }

    while(stCh->notEmpty())
    {
        stPost->add(stCh->top());
        stCh->pop();
    }

	AnsiString ans="";
    while(stPost->notEmpty())
    {
		ans+=(char)stPost->top();
		stPost->pop();
	}
	AnsiString s="";
	for (int j = strlen(ans.c_str()); j >0 ; --j) {
		s+=ans[j];
	}
	postForm->Items->Add(s);
	solve(s,result);
	}catch(...)
	{
	   postForm->Items->Add("invalid expression");
    }
    delete stCh;
	delete stPost;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AEditChange(TObject *Sender)
{
	if(AEdit->Text!="")
	{
		try
		{
			a=StrToFloat(AEdit->Text);
		}catch(...){
		   AEdit->Text="invalid input";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BEditChange(TObject *Sender)
{
	if(BEdit->Text!="")
	{
		try
		{
			b=StrToFloat(BEdit->Text);
		}catch(...){
		   BEdit->Text="invalid input";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CEditChange(TObject *Sender)
{
	 if(CEdit->Text!="")
	{
		try
		{
			c=StrToFloat(CEdit->Text);
		}catch(...){
		  CEdit->Text="invalid input";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DEditChange(TObject *Sender)
{
	if(DEdit->Text!="")
	{
		try
		{
			d=StrToFloat(DEdit->Text);
		}catch(...){
		   DEdit->Text="invalid input";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EEditChange(TObject *Sender)
{
	 if(EEdit->Text!="")
	{
		try
		{
			e=StrToFloat(EEdit->Text);
		}catch(...){
		   EEdit->Text="invalid input";
		}
	}
}
//---------------------------------------------------------------------------

