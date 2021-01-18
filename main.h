#pragma once
#include "wx-3.0/wx/wx.h"

class cmain : public wxFrame{
    public:
        cmain();
        ~cmain();
    public:
        int nFieldWidth  = 10;
        int nFieldHeight = 10;
        wxButton **btn;
        int *nField = nullptr;
        bool bFirstClick = true;

        void OnButtonClicked(wxCommandEvent &evt);
        
        wxDECLARE_EVENT_TABLE();
};