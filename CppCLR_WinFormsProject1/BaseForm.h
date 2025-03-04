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

            // Adjust row and column styles to ensure buttons have fixed sizes (50x50)
            for (int i = 0; i < 11; i++)  // We have 11 rows and columns due to labels
            {
                if (i == 0) {
                    // Set fixed size for row/column headers (labels)
                    this->buttonGrid->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50));  // Fixed height for the first row (labels)
                    this->buttonGrid->ColumnStyles->Add(gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 50));  // Fixed width for the first column (labels)
                }
                else {
                    // Set fixed size for buttons
                    this->buttonGrid->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50));  // Fixed height for buttons
                    this->buttonGrid->ColumnStyles->Add(gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 50));  // Fixed width for buttons
                }
            }

            // Create and add labels for the top (1-10) (columns)
            for (int col = 1; col <= 10; col++)
            {
                System::Windows::Forms::Label^ label = gcnew System::Windows::Forms::Label();
                label->Text = col.ToString();
                label->Dock = System::Windows::Forms::DockStyle::Fill;
                label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
                label->AutoSize = true;  // Ensure the label sizes itself to fit the content
                this->buttonGrid->Controls->Add(label, col, 0);  // Add labels in the first row (header)
            }

            // Create and add labels for the side (A-J) (rows)
            for (int row = 1; row <= 10; row++)
            {
                System::Windows::Forms::Label^ label = gcnew System::Windows::Forms::Label();
                label->Text = gcnew System::String((wchar_t)(L'A' + row - 1), 1);  // Convert to wchar_t A-J
                label->Dock = System::Windows::Forms::DockStyle::Fill;
                label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
                label->AutoSize = true;  // Ensure the label sizes itself to fit the content
                this->buttonGrid->Controls->Add(label, 0, row);  // Add labels in the first column (side header)
            }

            // Create and add blank buttons to the grid with border color
            for (int row = 1; row <= 10; row++)
            {
                for (int col = 1; col <= 10; col++)
                {
                    System::Windows::Forms::Button^ button = gcnew System::Windows::Forms::Button();
                    button->Text = "";  // Make the button blank
                    button->Width = 50;  // Set the button width to 50
                    button->Height = 50;  // Set the button height to 50
                    button->Margin = System::Windows::Forms::Padding(0);  // Remove margin between buttons
                    button->Padding = System::Windows::Forms::Padding(0);  // Remove padding inside the button
                    button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;  // Set flat style for custom border

                    // Custom border color (edge color)
                    button->FlatAppearance->BorderColor = buttonEdgeColor;  // Set the border color to custom edge color
                    button->FlatAppearance->BorderSize = 2;  // Set border size (you can adjust as needed)

                    this->buttonGrid->Controls->Add(button, col, row);  // Add the button to the grid at (col, row)
                }
            }

            // Add the button grid to the form
            this->Controls->Add(this->buttonGrid);
        }

    public:
        // Function to set the theme of the form and its controls
        void SetTheme(System::Drawing::Color backColor, System::Drawing::Color foreColor)
        {
            this->BackColor = backColor;
            this->ForeColor = foreColor;

            // Customize the appearance of buttons in the grid (e.g., set text color)
            for (int row = 0; row < 10; row++)
            {
                for (int col = 0; col < 10; col++)
                {
                    System::Windows::Forms::Control^ control = this->buttonGrid->GetControlFromPosition(col, row);
                    System::Windows::Forms::Button^ button = dynamic_cast<System::Windows::Forms::Button^>(control);
                    if (button != nullptr)
                    {
                        button->ForeColor = foreColor;  // Set text color for each button (though blank, can be changed)
                    }
                }
            }
        }

        // Method to change the button edge color
        void SetButtonEdgeColor(System::Drawing::Color newEdgeColor)
        {
            buttonEdgeColor = newEdgeColor;  // Update the edge color

            // Recreate the grid to apply the new edge color
            this->buttonGrid->Controls->Clear();  // Clear existing controls
            CreateGrid();  // Recreate grid with new edge color
        }

        // Method to change the background color of the buttons
        void SetButtonBackgroundColor(System::Drawing::Color newButtonColor)
        {
            for (int row = 0; row < 10; row++)
            {
                for (int col = 0; col < 10; col++)
                {
                    System::Windows::Forms::Control^ control = this->buttonGrid->GetControlFromPosition(col, row);
                    System::Windows::Forms::Button^ button = dynamic_cast<System::Windows::Forms::Button^>(control);
                    if (button != nullptr)
                    {
                        button->BackColor = newButtonColor;  // Set background color for each button
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
