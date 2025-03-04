#pragma once

namespace CppCLRWinFormsProject {

    public ref class BaseForm : public System::Windows::Forms::Form
    {
    protected:
        // Define the button grid (TableLayoutPanel)
        System::Windows::Forms::TableLayoutPanel^ buttonGrid;
        // Define a color for the button edges
        System::Drawing::Color buttonEdgeColor;

    public:
        BaseForm(System::Drawing::Color backColor, System::Drawing::Color foreColor, System::Drawing::Color edgeColor)
        {
            InitializeComponent();  // Call InitializeComponent in the constructor
            buttonEdgeColor = edgeColor;  // Set the button edge color
            CreateGrid();  // Create the grid layout
            SetTheme(backColor, foreColor);  // Apply custom theme
        }

    private:
        // Function to create a 10x10 grid with blank buttons of size 50x50 and custom borders
        void CreateGrid()
        {
            this->buttonGrid = gcnew System::Windows::Forms::TableLayoutPanel();
            this->buttonGrid->RowCount = 11;  // 10 rows for the grid + 1 row for labels
            this->buttonGrid->ColumnCount = 11;  // 10 columns for the grid + 1 column for labels
            this->buttonGrid->Dock = System::Windows::Forms::DockStyle::Fill;

            // Set row and column styles for proper alignment
            for (int i = 0; i < 11; i++)  // Includes labels
            {
                this->buttonGrid->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50));
                this->buttonGrid->ColumnStyles->Add(gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 50));
            }

            // Create and add labels for the top (1-10) (columns)
            for (int col = 1; col <= 10; col++)
            {
                System::Windows::Forms::Label^ label = gcnew System::Windows::Forms::Label();
                label->Text = col.ToString();
                label->Dock = System::Windows::Forms::DockStyle::Fill;
                label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
                label->AutoSize = false;
                label->Size = System::Drawing::Size(50, 50);  // Force exact size
                label->MinimumSize = System::Drawing::Size(49, 49);
                label->MaximumSize = System::Drawing::Size(49, 49);

                this->buttonGrid->Controls->Add(label, col, 0);  // Add labels in the first row
            }

            // Create and add labels for the side (A-J) (rows)
            for (int row = 1; row <= 10; row++)
            {
                System::Windows::Forms::Label^ label = gcnew System::Windows::Forms::Label();
                label->Text = gcnew System::String((wchar_t)(L'A' + row - 1), 1);
                label->Dock = System::Windows::Forms::DockStyle::Fill;
                label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
                label->AutoSize = false;
                label->Size = System::Drawing::Size(50, 50);  // Force exact size
                label->MinimumSize = System::Drawing::Size(45, 45);
                label->MaximumSize = System::Drawing::Size(45, 45);

                this->buttonGrid->Controls->Add(label, 0, row);  // Add labels in the first column
            }


            // Create and add buttons to the grid
            for (int row = 1; row <= 10; row++)
            {
                for (int col = 1; col <= 10; col++)
                {
                    System::Windows::Forms::Button^ button = gcnew System::Windows::Forms::Button();
                    button->Text = "";
                    button->Width = 50;
                    button->Height = 50;
                    button->Margin = System::Windows::Forms::Padding(0);
                    button->Padding = System::Windows::Forms::Padding(0);
                    button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
                    button->FlatAppearance->BorderColor = buttonEdgeColor;
                    button->FlatAppearance->BorderSize = 2;

                    this->buttonGrid->Controls->Add(button, col, row);
                }
            }

            // Add the TableLayoutPanel to the form
            this->Controls->Add(this->buttonGrid);
        }

    public:
        // Function to set the theme of the form and its controls
        void SetTheme(System::Drawing::Color backColor, System::Drawing::Color foreColor)
        {
            this->BackColor = backColor;
            this->ForeColor = foreColor;

            // Customize the appearance of buttons in the grid (e.g., set text color)
            for (int row = 1; row <= 10; row++)
            {
                for (int col = 1; col <= 10; col++)
                {
                    System::Windows::Forms::Control^ control = this->buttonGrid->GetControlFromPosition(col, row);
                    System::Windows::Forms::Button^ button = dynamic_cast<System::Windows::Forms::Button^>(control);
                    if (button != nullptr)
                    {
                        button->ForeColor = foreColor;
                    }
                }
            }
        }

        // Method to change the button edge color
        void SetButtonEdgeColor(System::Drawing::Color newEdgeColor)
        {
            buttonEdgeColor = newEdgeColor;

            // Recreate the grid to apply the new edge color
            this->buttonGrid->Controls->Clear();
            CreateGrid();
        }

        // Method to change the background color of the buttons
        void SetButtonBackgroundColor(System::Drawing::Color newButtonColor)
        {
            for (int row = 1; row <= 10; row++)
            {
                for (int col = 1; col <= 10; col++)
                {
                    System::Windows::Forms::Control^ control = this->buttonGrid->GetControlFromPosition(col, row);
                    System::Windows::Forms::Button^ button = dynamic_cast<System::Windows::Forms::Button^>(control);
                    if (button != nullptr)
                    {
                        button->BackColor = newButtonColor;
                    }
                }
            }
        }

    private:
        // Manually defining InitializeComponent method in BaseForm
        void InitializeComponent(void)
        {
            this->SuspendLayout();
            // 
            // BaseForm
            // 
            this->Name = L"BaseForm";
            this->Text = L"Base Form with 10x10 Grid";
            this->ResumeLayout(false);
        }
    };
}
