#pragma once
#include "BaseForm.h"

namespace CppCLRWinFormsProject {

    public ref class Form1 : public BaseForm  // Inherit from BaseForm
    {
    public:
        Form1(void)
            : BaseForm(System::Drawing::Color::Black, System::Drawing::Color::FromArgb(0, 255, 0), System::Drawing::Color::FromArgb(0, 255, 0)) // Pass the required parameters to the base class constructor
        {
            InitializeComponent();  // Initialize Form1 components
        }

    private:
        void InitializeComponent(void)
        {
            this->SuspendLayout();
            // Form1 initialization code
            this->ClientSize = System::Drawing::Size(700, 700);
            this->Name = L"Form1";
            this->Text = L"Form1 - Inherited from BaseForm";
            this->ResumeLayout(false);
        }
    };
}