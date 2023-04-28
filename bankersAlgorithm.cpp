//Thomas Denvir - 4/28/23
//Operating Systems
//Bankers Algorithm Simulation
//Will not compile. attempting to compile crashes the terminal.
//This is my third randition of this code, this one was made
//without the input text file or custom value requests/releases from the
//user. Any help as to why this wont compile would be much appricated.
#include <iostream>
#include <vector>

using namespace std;
//previously were const, but changed it to help generate Need (not a good way to do this)
 int num_P = 5;
 int m_numR = 3;

vector<vector<int>> maxResources = {{7 , 5 , 3},
                                    {3 , 2 , 2},
                                    {9 , 0 , 2},
                                    {2 , 2 , 2},
                                    {4 , 3 , 3}};

vector<int> availableResources = {10 , 5, 7};

vector<vector<int>> allocation = {{0 , 1 , 0},
                                  {2 , 0 , 0},
                                  {3 , 0 , 2},
                                  {2 , 1 , 1},
                                  {0 , 0 , 2}};


                        // I                  J
vector<vector<int>> Need(num_P , vector<int>(m_numR));

vector<vector<int>> generateNeed(vector<vector<int>>);
vector<vector<int>> generateNeed(vector<vector<int>> Need){
for(int i = 0; i < num_P; i++){
    for(int j = 0; i < num_P; j++){
        Need[i][j] = maxResources[i][j] - allocation[i][j];
    }
} return Need;
};

struct State{
    vector<vector<int>> allocation;
    vector<vector<int>> need;
    vector<int> availableResources;
};
bool safeCheck(State, int, vector<int>);
bool safeCheck(State state, int process, vector<int> request){
    vector<int> new_availableResources(m_numR);
    vector<vector<int>> new_allocation(num_P, vector<int>(m_numR));
    vector<vector<int>> new_need(num_P, vector<int>(m_numR));

//only have to generate the next line, so using a 1D vector is fine
    for(int i = 0; i < num_P; i++){
        new_availableResources[i]  = state.availableResources[i]  - request[i];
        new_allocation[process][i] = state.allocation[process][i] + request[i];
        new_need[process][i]       = state.need[process][i]       - request[i];
    }

    //Safety algorithm - Step 1:
    vector<int> work = new_availableResources;
    vector<bool> finish(num_P, false);

    int count = 0;
    while (count < num_P)
    {
        bool found = false;
        for(int i = 0; i < num_P; i++){
            //Safety Algorithm - Step 2
            if(!finish[i]){
                bool can_allo = true;
                for(int j = 0; j < m_numR; j++){
                    if(new_need[i][j] > work[j]){
                        can_allo = false;
                        break;
                    }
                }
                //Safety Algorithm - Step 3
                if(can_allo){
                    for(int j = 0; j < m_numR; j++){
                        work[j] = new_allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }
        if(!found){
            break;
        }
    }
    //Safety Algorithm - Step 4
    return (count == num_P);
}
State requestRes(State, int, vector<int>);
State requestRes(State state, int process, vector<int> request){
    //is this even possible check
    if(!safeCheck(state,process,request)){
        std::cout << "Not safe" << std::endl;
        return state;
    }
    vector<int> new_availableResources = state.availableResources;
    vector<vector<int>> new_allocation = state.allocation;
    vector<vector<int>> new_need       = state.need;

    for(int i = 0 ; i < m_numR; i++){
        new_availableResources[i]  -= request[i];
        new_allocation[process][i] += request[i];
        new_need[process][i]       -= request[i];
    }
    State new_state = {new_allocation, new_need, new_availableResources};
    return new_state;
}
State releaseRes(State, int, vector<int>);
State releaseRes(State state, int process, vector<int> release){
    vector<int> new_availableResources = state.availableResources;
    vector<vector<int>> new_allocation = state.allocation;
    vector<vector<int>> new_need       = state.need;

    for(int i = 0; i < m_numR; i++){
        new_availableResources[i]  += release[i];
        new_allocation[process][i] -= release[i];
        new_need[process][i]       += release[i];
    }

    State new_state = {new_allocation,new_need,new_availableResources};
    return new_state;
}

int main(){
    State state = {allocation,generateNeed(Need),availableResources};
    vector<int> request = {0, 1, 0};
    state = requestRes(state,1,request);

    vector<int> release = {2, 0, 0};
    state = releaseRes(state, 2, release);


    return 0;
}