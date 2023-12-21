#include <iostream>
#include "TJobStream.h"
#include "TQueue.h"
#include "TStack.h"
#include "TProc.h"

using namespace System;
using namespace System::Windows::Forms;
namespace La4 {
	ref class MyForm : public Form
	{
	private:
		TJobStream* jobStream;
		TQueue* queue;
		TStack* stack;
		TProc* processor;
		TextBox^ outputTextBox;
		Button^ button;
    public:
        MyForm()
        {

            InitializeFormComponents();

            jobStream = new TJobStream(0.5);
            queue = new TQueue();
            stack = new TStack();
            processor = new TProc();


            RunSimulation();
        }

    private:
        void InitializeFormComponents()
        {

            outputTextBox = gcnew TextBox();
            outputTextBox->Multiline = true;
            outputTextBox->Dock = DockStyle::Fill;
            outputTextBox->ReadOnly = true;
            outputTextBox->BackColor = System::Drawing::Color::Green;
            outputTextBox->ForeColor = System::Drawing::Color::White;
            outputTextBox->Font = gcnew System::Drawing::Font("Arial", 12, System::Drawing::FontStyle::Bold);

            button = gcnew Button();

            button->Text = "Нажмите здесь";
            button->Size = System::Drawing::Size(100, 50);
            button->BackColor = System::Drawing::Color::LightBlue;
            button->ForeColor = System::Drawing::Color::White;
            button->Font = gcnew System::Drawing::Font("Arial", 12, System::Drawing::FontStyle::Bold);
            button->Click += gcnew EventHandler(this, &MyForm::ButtonClick);

            this->Text = "Job Processing Simulation";
            this->Size = System::Drawing::Size(400, 500);
            this->Controls->Add(outputTextBox);
            this->Controls->Add(button);
        }

        void PrintOutput(String^ text)
        {
            outputTextBox->AppendText(text + "\r\n");
        }

        void RunSimulation()
        {
            for (int i = 1; i <= 10; i++)
            {
                int newJob = jobStream->GetNewJob();
                if (newJob != 0)
                {
                    queue->Enqueue(newJob);
                    PrintOutput("Работа " + newJob + " добавлена в очередь.");
                }

                if (!queue->IsEmpty() && !processor->IsActive())
                {
                    int jobInProcess = queue->Front();
                    queue->Dequeue();
                    processor->SetActiveJob(jobInProcess);
                    PrintOutput("Работа " + jobInProcess + " перемещена из очереди в процессор.");
                }

                if (processor->IsActive()) {
                    int ActiveJob;
                    ActiveJob++;
                    PrintOutput("Работа " + ActiveJob + " обрабатывается процессором");
                }
                processor->ProcessJob();

                PrintOutput("");
            }
        }

        void ButtonClick(Object^ sender, EventArgs^ e)
        {
            
        }
    private: System::Void InitializeComponent() {
        this->SuspendLayout();

        this->BackColor = System::Drawing::Color::Green;
        this->ClientSize = System::Drawing::Size(284, 261);
        this->Name = L"MyForm";
        this->ResumeLayout(false);
    }
    };

    [STAThread]
    int main(array<String^>^ args)
    {
        Application::EnableVisualStyles();
        Application::SetCompatibleTextRenderingDefault(false);
        Application::Run(gcnew MyForm());
        return 0;
    }
}