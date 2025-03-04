#pragma once
#include "BaseForm.h"

namespace CppCLRWinFormsProject {

    public ref class Form2 : public BaseForm  // Inherit from BaseForm
    {
    public:
        Form2(void)
            : BaseForm(System::Drawing::Color::Black, System::Drawing::Color::FromArgb(255, 49, 49), System::Drawing::Color::FromArgb(255, 49, 49)) // Pass the required parameters to the base class constructor
        {
            InitializeComponent();  // Initialize Form1 components
        }

    private:
        void InitializeComponent(void)
        {
            this->SuspendLayout();
            // Form1 initialization code
            this->ClientSize = System::Drawing::Size(700, 700);
            this->Name = L"Form2";
            this->Text = L"Form2 - Inherited from BaseForm";
            this->ResumeLayout(false);
        }
    };
}