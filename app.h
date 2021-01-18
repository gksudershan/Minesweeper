#pragma once
#include "wx-3.0/wx/wx.h"
#include "main.h"

class app: public wxApp{
    public:
        app();
        ~app();

    private:
        cmain *m_frame1 = nullptr;

    public:
        virtual bool OnInit();
};