#pragma once
#include<wx/wxprec.h>

#ifndef WX_PRECOMP
#include<wx/wx.h>
#endif

class MyApp : public wxApp
{
public:
	virtual bool OnInit();

};

class MyFrame : public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	
	wxButton* AddCR;
	wxButton* AddLA;
	wxButton* AddDR;
	wxButton* GenTableS;
	wxButton* GenTableT;
	wxButton* Quit;

	wxString daysofweek[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	static wxString classpath;
	static wxString lecturerpath;
	static wxString departpath;

	void OnAddLA(wxCommandEvent& event);
	void OnAddDR(wxCommandEvent& event);
	void OnAddCR(wxCommandEvent& event);
	void OnGenTableS(wxCommandEvent& event);
	void OnGenTableT(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);

	DECLARE_EVENT_TABLE()
};
wxString MyFrame::classpath = "a";
wxString MyFrame::lecturerpath = "a";
wxString MyFrame::departpath = "a";
class TableFrame : public wxFrame
{
public:
	TableFrame(const wxString& title1);
};

enum {
	ID_AddCR = wxID_HIGHEST + 1,
	ID_AddLA,
	ID_AddDR,
	ID_GenTableS,
	ID_GenTableT,
	ID_Quit
};
