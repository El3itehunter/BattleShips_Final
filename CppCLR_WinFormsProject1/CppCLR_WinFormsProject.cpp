#include "pch.h"
#include "Form1.h"
#include "Form2.h"  // ✅ Include Form2.h

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create instances of Form1 and Form2
    CppCLRWinFormsProject::Form1^ form1 = gcnew CppCLRWinFormsProject::Form1();
    CppCLRWinFormsProject::Form2^ form2 = gcnew CppCLRWinFormsProject::Form2(); 

    // Set their positions manually
    form1->StartPosition = FormStartPosition::Manual;
    form1->Location = System::Drawing::Point(100, 100);

    form2->StartPosition = FormStartPosition::Manual;
    form2->Location = System::Drawing::Point(800, 100);  // Right of Form1

    // Show both forms
    form1->Show();
    form2->Show();

    Application::Run();  // Runs the message loop

    return 0;
}
