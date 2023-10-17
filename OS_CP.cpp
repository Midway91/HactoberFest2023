#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
class PCB
{
public:
    int jobID, TTL, TLL;
    int TTC, LLC;
};

class VM
{
private:
    fstream infile;
    ofstream outfile;
    char Memory[300][4], buffer[40], IR[4], R[4];
    bool C;
    int IC;
    int SI, PI, TI;
    PCB pcb;
    int PTR;
    int PTE;
    int RA, VA;
    int visited[30];
    int pageTablePTR;
    int page_fault_valid = 0; // 1-Valid  0-Invalid
    bool Terminate;
    int pageNo;
    bool run_mos;

    void init()
    {
        fill(buffer, buffer + sizeof(buffer), ' ');
      //  fill(&Memory[0][0], &Memory[0][0] + sizeof(Memory), ' ');
        //fill(IR, IR + sizeof(IR), '\0');
        //fill(R, R + sizeof(R), '\0');

        // for(int i =0; i< 30 ; i++)
        // {
        // buffer[i]='\0';
        // }

        for (int i = 0; i < 300; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                Memory[i][j] = ' ';
            }
        }

        for (int i = 0; i < 4; i++) // Initialize IR and R
        {
            IR[i] = '\0';
            R[i] = '\0';
        }


        C = true;
        IC = 0;
        SI = PI = TI = 0;

        pcb.jobID = pcb.TLL = pcb.TTL = pcb.TTC = pcb.LLC = 0;
        PTR = PTE = pageNo = -1;
        //fill(pageTable, pageTable + sizeof(pageTable), 0);
        for(int i =0; i<30; i++)
        {
            visited[i] = 0;
        }
        pageTablePTR = 0;
        Terminate = false;
    }

    void restBuffer()
    {
        fill(buffer, buffer + sizeof(buffer), ' ');
        // for(int i =0; i< 30 ; i++)
        // {
        // buffer[i]='\0';
        // }
    }

    int Allocate()
    {
        int pageNo;
        bool check = true;
        while (check)
        {
            pageNo = (rand() % 30);
            if (visited[pageNo] == 0)
            {
                visited[pageNo] = 1;
                check = false;
            }
        }

        return pageNo;
    }

    void MOS()
    { // Master Mode

        // Case TI and SI
        if (TI == 0 && SI == 1)
        {
            READ();
        }
        else if (TI == 0 && SI == 2)
        {
            WRITE();
        }
        else if (TI == 0 && SI == 3)
        {
            TERMINATE(0);
        }
        else if (TI == 2 && SI == 1)
        {
            TERMINATE(3);
        }
        else if (TI == 2 && SI == 2)
        {
            WRITE();
            TERMINATE(3);
        }
        else if (TI == 2 && SI == 3)
        {
            TERMINATE(0);
        }

        // Case TI and PI
        else if (TI == 0 && PI == 1)
        {
            TERMINATE(4);
        }
        else if (TI == 0 && PI == 2)
        {
            TERMINATE(5);
        }
        else if (TI == 0 && PI == 3)
        {

            if (page_fault_valid == 1)
            {
                cout << "Valid Page Fault:   ";
                pageNo = Allocate();
                Memory[PTE][2] = (pageNo / 10) + '0';
                Memory[PTE][3] = (pageNo % 10) + '0';
                pageTablePTR++;
                PI = 0;
                cout << "Allocated Page Number: " << pageNo << "\n";
            }
            else
            {
                pcb.TTC--;
                TERMINATE(6);
            }
        }
        else if (TI == 2 && PI == 1)
        {
            TERMINATE(3);
        }
        else if (TI == 2 && PI == 2)
        {
            TERMINATE(3);
        }
        else if (TI == 2 && PI == 3)
        {
            TERMINATE(3);
        }
    }

    void READ()
    {
        cout << "Read function called\n";

        string data;
        getline(infile, data);
        if (data[0] == '$' && data[1] == 'E' && data[2] == 'N' && data[3] == 'D')
        {
            pcb.TTC--;
            TERMINATE(1);
            return;
        }
        int len = data.size();
        for (int i = 0; i < len; i++)
        {
            buffer[i] = data[i];
        }

        int buff = 0, mem_ptr = RA, end = RA + 10;
        while (buff < 40 && buffer[buff] != '\0' && mem_ptr < end)
        {
            for (int i = 0; i < 4; i++)
            {
                Memory[mem_ptr][i] = buffer[buff];
                buff++;
            }
            mem_ptr++;
        }

        // for(int i=0;i<300;i++){
        //                 if(i==PTR){
        //                     cout<<"---Page Table---\n";
        //                 }
        //                 if(i==PTR+10){
        //                     cout<<"--Page Table End--\n";
        //                 }
        //                 cout<<"[ "<<i<<" ] : ";

        //                 for(int j=0;j<4;j++){
        //                     cout<<Memory[i][j]<<" ";
        //                 }
        //                 cout<<'\n';
        //             }
        restBuffer();
        SI = 0;
    }

    void WRITE()
    {
        cout << "Write function called\n";

        pcb.LLC++;
        if (pcb.LLC > pcb.TLL)
        {
            pcb.LLC--;
            TERMINATE(2);
            return;
        }

        outfile.open("output.txt", ios::app);
           string output;
        // bool flag = true;
        // for (int i = RA; i < RA + 10; i++)
        // {
        //     for (int j = 0; j < 4; j++)
        //     {
        //         if (Memory[i][j] != '\0')
        //         {
        //             outfile << Memory[i][j];
        //         }
        //         else
        //         {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if (!flag)
        //     {
        //         break;
        //     }
        // }


            int i=RA;
            char buffeer[40];
            string s;
            int k = 0;
            // for (int l = 0; l < 10; ++l)
            // {
            //     for (int j = 0; j < 4; ++j)
            //     {
            //        // buffeer[k] = Memory[i][j];
            //         outfile <<  Memory[i][j];
            //         if (buffeer[k]!='\0'){
            //             s += Memory[i][j];
            //            // outfile << buffeer[k];

            //            // cout<<buffeer[k];
            //         }
            //         k++;
            //     }

            //     if (k == 40)
            //     {
            //         break;
            //     }
            //     i++;
            // }
            //   outfile << s << "\n";

            if (RA != -1)
    {
        for (int i = RA; i < RA + 10; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                output += Memory[i][j];
            }
        }

        outfile << output << "\n";
    }
    else
    {
        TERMINATE(5); // Operand Error
        return;
    }






        SI = 0;
        outfile << "\n";
        outfile.close();
    }

    void TERMINATE(int EM)
    {
        Terminate = true;
        outfile.open("output.txt", ios::app);
        outfile << "\n";
        outfile << "Job Id :" << pcb.jobID << "\n";
        switch (EM)
        {
        case 0:
            outfile << "No Error: PROGRAM EXECUTED SUCCESSFULLY\n";
            break;
        case 1:
            outfile << "Error: OUT IF DATA ERROR\n";
            break;
        case 2:
            outfile << "Error: LINE LIMIT EXCEEDED\n";
            break;
        case 3:

            if (TI == 2 && PI == 1)
            {
                outfile << "Error: OPERATION CODE ERROR\n";
            }
            if (TI == 2 && PI == 2)
            {
                outfile << "Error: OPERAND ERROR\n";
            }
            outfile << "Error: TIME LIMIT EXCEEDED\n";

            break;
        case 4:
            outfile << "Error: OPERATION CODE ERROR\n";
            break;
        case 5:
            pcb.TTC--;
            outfile << "Error: OPERAND ERROR\n";
            break;
        case 6:
            outfile << "Error: INVAILD PAGE FAULT\n";
        }
        outfile << "IC: " << IC << "\n";
        outfile << "IR: ";
        for (int i = 0; i < 4; i++)
        {
            if (IR[i] != '\0')
                outfile << IR[i];
        }
        outfile << "\n";
        //outfile << "SI: " << SI << "  ";
        //outfile << "PI: " << PI << "  ";
        //outfile << "TI: " << TI << "  ";
        //outfile << "TLL: " << pcb.TLL << "  ";
        outfile << "TTC: " << pcb.TTC << "\n";
        outfile << "LLC: " << pcb.LLC << "\n";
        //outfile << "TTL: " << pcb.TTL << "  ";


        outfile << "\n\n\n";
        SI = 0;
        PI = 0;
        TI = 0;

        outfile.close();
    }

    void LOAD()
    {

        if (infile.is_open())
        {
            string s;
            while (getline(infile, s))
            {
                if (s[0] == '$' && s[1] == 'A' && s[2] == 'M' && s[3] == 'J')
                {
                    /*  $AMJ  0001 0003 0001
                             jobID  TTL  TLL  */
                    init();
                    cout << "New Job started\n";
                    pcb.jobID = (s[4] - '0') * 1000 + (s[5] - '0') * 100 + (s[6] - '0') * 10 + (s[7] - '0');
                    pcb.TTL = (s[8] - '0') * 1000 + (s[9] - '0') * 100 + (s[10] - '0') * 10 + (s[11] - '0');
                    pcb.TLL = (s[12] - '0') * 1000 + (s[13] - '0') * 100 + (s[14] - '0') * 10 + (s[15] - '0');

                    // Get Frame for Page Table
                    PTR = Allocate() * 10;
                    for (int i = PTR; i < PTR + 10; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            Memory[i][j] = '*';
                        }
                    }
                    cout << "\nAllocated Page is for Page Table: " << PTR / 10 << "\n";
                    cout << "jobID: " << pcb.jobID << "\nTTL: " << pcb.TTL << "\nTLL: " << pcb.TLL << "\n";
                }

                else if (s[0] == '$' && s[1] == 'D' && s[2] == 'T' && s[3] == 'A')
                {
                    cout << "Data card loding\n";
                    restBuffer();
                    MOSstartexe();
                }

                else if (s[0] == '$' && s[1] == 'E' && s[2] == 'N' && s[3] == 'D')
                {
                    cout << "END of Job\n";
                    for(int i=0;i<300;i++){
                        if(i==PTR){
                            cout<<"---Page Table---\n";
                        }
                        if(i==PTR+10){
                            cout<<"--Page Table End--\n";
                        }
                        cout<<"[ "<<i<<" ] : ";

                        for(int j=0;j<4;j++){
                            cout<<Memory[i][j]<<" ";
                        }
                        cout<<'\n';
                    }
                }

                else
                {
                    restBuffer();
                    // Get Frame for Program Page
                    pageNo = Allocate();
                    Memory[PTR + pageTablePTR][2] = (pageNo / 10) + '0';
                    Memory[PTR + pageTablePTR][3] = (pageNo % 10) + '0';
                    pageTablePTR++;

                    cout << "Program Card loding\n";
                    cout<< "Allocated pageno. for prog card="<<pageNo<<"\n";
                    int length = s.size();

                    // Buffer <-- Program Card
                    for (int i = 0; i < length; i++)
                    {
                        buffer[i] = s[i];
                    }

                    int buff = 0;
                    IC = pageNo * 10;
                    int end = IC + 10;

                    // Memory <-- Buffer
                    while (buff < 40 && buffer[buff] != '\0' && IC < end)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            if (buffer[buff] == 'H')
                            {
                                Memory[IC][j] = 'H';
                                buff++;
                                break;
                            }
                            Memory[IC][j] = buffer[buff];
                            buff++;
                        }
                        IC++;
                    }
                }
            }
            infile.close(); // card File closed
        }
    }

    int ADDRESSMAP(int VA)
    {
        if (0 <= VA && VA < 100)
        {
            PTE = PTR + (VA / 10);
            if (Memory[PTE][2] == '*')
            {
                PI = 3; // Page fault no such page exist
                cout<<"\npage fault occured";
                cout<<"\nTI= "<<TI<<"\nSI= "<<SI<<"\nPI= "<<PI;
                MOS();
            }
            else
            {
                string p;
                p = Memory[PTE][2];
                p += Memory[PTE][3];
                int pageNo = stoi(p);
                RA = pageNo * 10 + (VA % 10);
                cout << "\nreturned RA= "<<RA;
                return RA;
            }
        }
        else
        {
            PI = 2; // Operand Error;
            cout<<"\noperand error called";

            MOS();
        }
        return pageNo * 10;
    }

    void MOSstartexe()
    {
        IC = 0;
        executeUserProgram();
    }

    void executeUserProgram()
    { // Slave Mode
        while (!Terminate)
        {
            RA = ADDRESSMAP(IC);
            if (PI != 0)
            {
                return;
            }

            for (int i = 0; i < 4; i++)
            {
                IR[i] = Memory[RA][i];
            }
            cout<<"Instruction register"<<endl;
            for (int i = 0; i < 4 ; i++)
            {
                cout<<IR[i];
            }
            cout<<endl;


            IC++;

            string op;
            op += IR[2];
            op += IR[3];
            cout<<"\ninstruct = "<<IR[0]<<IR[1]<<IR[2]<<IR[3];
            // GD - GET DATA
            if (IR[0] == 'G' && IR[1] == 'D')
            {
                SIMULATION();
                page_fault_valid = 1;
                if (!isdigit(IR[2]) || !isdigit(IR[3]))
                {
                    PI = 2;
                     run_mos=true;
                   // MOS();
                }
                else
                {
                    VA = stoi(op);
                    cout<<"\nvirtual address= "<<VA;
                    RA = ADDRESSMAP(VA);
                    cout<<RA<<endl;
                    SI = 1;
                     run_mos=true;
                   // MOS();
                }
            }

            // PD - PRINT DATA
            else if (IR[0] == 'P' && IR[1] == 'D')
            {
                SIMULATION();
                page_fault_valid = 0;
                if (!isdigit(IR[2]) || !isdigit(IR[3]))
                {
                    PI = 2;
                    pcb.TTC--;
                    run_mos=true;
                    //MOS();
                }
                else
                {
                    VA = stoi(op);
                    RA = ADDRESSMAP(VA);
                    SI = 2;
                    run_mos=true;
                   // MOS();
                }
            }

            // H - HALT
            else if (IR[0] == 'H' && IR[1] == '\0')
            {
                SIMULATION();
                SI = 3;
                run_mos=true;
               // MOS();
                return;
            }

            // LR - LOAD DATA (Register  <- Memory)
            else if (IR[0] == 'L' && IR[1] == 'R')
            {
                SIMULATION();
                page_fault_valid = 0;
                if (!isdigit(IR[2]) || !isdigit(IR[3]))
                {
                    PI = 2;
                    run_mos=true;
                   // MOS();
                }
                else
                {
                    VA = stoi(op);
                    RA = ADDRESSMAP(VA);
                    for (int i = 0; i < 4; i++)
                    {
                        R[i] = Memory[RA][i];
                    }
                }
            }

            // SR - STORE (Memory  <-  Register)
            else if (IR[0] == 'S' && IR[1] == 'R')
            {
                cout<<"\n Inside SR";
                SIMULATION();
                page_fault_valid = 1;
                if (!isdigit(IR[2]) || !isdigit(IR[3]))
                {
                    PI = 2;
                    run_mos=true;
                    //MOS();
                }

                else
                {
                    VA = stoi(op);


                    RA = ADDRESSMAP(VA);

                    for (int i = 0; i < 4; i++)
                    {
                        Memory[RA][i] = R[i];

                    }
                }

            }

            // CR - COMPARE
            else if (IR[0] == 'C' && IR[1] == 'R')
            {
                SIMULATION();
                page_fault_valid = 0;
                if (!isdigit(IR[2]) || !isdigit(IR[3]))
                {
                    PI = 2;
                    run_mos=true;
                    //MOS();
                }
                else
                {
                    VA = stoi(op);
                    RA = ADDRESSMAP(VA);
                    string s1, s2;
                    for (int i = 0; i < 4; i++)
                    {
                        s1 += Memory[RA][i];
                        s2 += R[i];
                    }
                    if (s1 == s2)
                    {
                        C = true;
                    }
                    else
                    {
                        C = false;
                    }
                }
            }

            // BT (JUMP if toogle is T)
            else if (IR[0] == 'B' && IR[1] == 'T')
            {
                SIMULATION();
                page_fault_valid = 0;
                if (!isdigit(IR[2]) || !isdigit(IR[3]))
                {
                    PI = 2;
                    run_mos=true;
                    //MOS();
                }
                else
                {
                    if (C)
                    {
                        string j;
                        j += IR[2];
                        j += IR[3];
                        IC = stoi(j);
                    }
                }
            }
            else
            {
                SIMULATION();
                PI = 1;
                SI = 0;
                pcb.TTC--;
                 run_mos=true;
               // MOS();
            }
            if(run_mos)
            {
                cout<<"\nMOS called for- "<<IR[0]<<IR[1]<<IR[2]<<IR[3];
                MOS();
            }

        }
    }

    void SIMULATION()
    {
        if (IR[0] == 'G' && IR[1] == 'D')
        {
            pcb.TTC += 1;
        }

        else if (IR[0] == 'P' && IR[1] == 'D')
        {
            pcb.TTC += 1;
        }

        else if (IR[0] == 'H')
        {
            pcb.TTC += 1;
        }

        else if (IR[0] == 'L' && IR[1] == 'R')
        {
            pcb.TTC += 1;
        }

        else if (IR[0] == 'S' && IR[1] == 'R')
        {
            pcb.TTC += 1;
        }

        else if (IR[0] == 'C' && IR[1] == 'R')
        {
            pcb.TTC += 1;
        }

        else if (IR[0] == 'B' && IR[1] == 'T')
        {
            pcb.TTC += 1;
        }
        else
        {
            pcb.TTC +=1;
        }

        if (pcb.TTC > pcb.TTL)
        {
            TI = 2;
           // MOS();
            run_mos = true;
        }
    }

public:
    VM()
    {
        infile.open("input_phase2.txt", ios::in);

        init();
        LOAD();
    }
};

int main()
{
    VM vm;
    return 0;
}
