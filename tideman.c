#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool is_forming_circle(int Starting_index);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    //printf("rank:%i\nCandidate Name: %s\n",rank,name);
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            //printf("rank:%i\n Candidate Name: %s\n",ranks[rank],candidates[i]);
            return true;
        }

    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        preferences[ranks[i]][ranks[i]] = 0;
        for (int j = i + 1; j < candidate_count; j++)
        {
            //printf("%i\n",ranks[i]);
            preferences[ranks[i]][ranks[j]]++;

        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences [i][j] > preferences [j][i] && preferences [i][j] != preferences [j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                //printf("winner is %s:%i \n", candidates [pairs[pair_count].winner], pairs[pair_count].winner);
                //printf("Loser is %s:%i \n", candidates [pairs[pair_count].loser], pairs[pair_count].loser);
                pair_count ++;
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int max = i;
        for (int j = i; j < pair_count - 1; j++)

        {
            int w = pairs[j].winner;
            int l = pairs[j].loser;
            int w1 = pairs[j + 1].winner; // Saves the Candidate index number for winner
            int l1 = pairs[j + 1].loser; // Saves the Candidate index number for loser

            if ((preferences [w][l]) - (preferences [l][w]) < (preferences [w1][l1]) - (preferences [l1][w1]))
            {
                max = j + 1;
            }
        }
        int tempw;
        int templ;
        tempw = pairs[i].winner;
        templ = pairs[i].loser;
        pairs[i].winner = pairs[max].winner;
        pairs[i].loser = pairs[max].loser;
        pairs[max].winner = tempw;
        pairs[max].loser = templ;

        //printf("Sorted pair(%i) = winner:%i loser:%i\n",i+1,pairs[i].winner,pairs[i].loser);
    }

    // TODO


    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int w = pairs[i].winner;
        int l = pairs[i].loser;
        //if (i == 0)
        locked[w][l] = true;
        if (is_forming_circle(w))
        {
            locked[w][l] = false;
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    bool loser[candidate_count];
    for (int l = 0; l < candidate_count; l++)
    {
        loser[l] = false;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == true)
            {
                loser[j] = true;
            }
        }
    }
    
    for (int k = 0; k < candidate_count; k++)
    {
        if (loser[k] == false)
        {
            printf("%s\n", candidates[k]);
        }
    }

    return;
}

bool helper(int index, bool visited[])
{
    if (visited[index] == true)
    {
        return true;
    }
    visited[index] = true;
    for (int i = 0; i < candidate_count; i++)
    {
        if ((locked[i][index]) && (helper(i, visited)))
        {    
            return true;
        }    
    }
    return false;
}

//recursion function to check fro circle
bool is_forming_circle(int Starting_index)
{
    bool visited[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        visited[i] = false;
    }
    return helper(Starting_index, visited);
}