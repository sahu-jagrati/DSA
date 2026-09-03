// A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.

// You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.

// A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:

// seats 2, 3, 4, 5
// seats 4, 5, 6, 7
// seats 6, 7, 8, 9
// A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.

// Return an integer denoting the maximum number of four-person groups that can be assigned.

// Example 1:

// Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
// Output: 4
// Explanation: The figure above shows an optimal allocation of four groups. Seats marked in blue are already reserved, and each set of four contiguous seats marked in orange is assigned to one group.
// Example 2:

// Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
// Output: 2
// Example 3:

// Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
// Output: 4

// Constraints:

// 1 <= n <= 10^9
// 1 <= reservedSeats.length <= min(10 * n, 10^4)
// reservedSeats[i] == [rowi, seati]
// 1 <= rowi <= n
// 1 <= seati <= 10
// All reservedSeats[i] are distinct.

// Hint 1
// Note you can allocate at most two four-person groups in one row.
// Hint 2
// Greedily check if you can allocate seats for two groups, one group or none.
// Hint 3
// Process only rows that appear in the input, for other rows you can always allocate seats for two groups.

#include <bits/stdc++.h>
using namespace std;

// I solved this problem using hint

// for each row we have three blocks of four-person groups:
// block1= 2,3,4,5
// block2=4,5,6,7
// block3=6,7,8,9
// so for each row, we can allocate atmost two four-person groups
// so we can allocate seats for  two gorup or one group, or none
// 1.  we can allocate two group in : block1 and block3 if in there any seats are not reserved in that case we cannot take block2 because block2 overlap with block1 and block3

// 2.  we can allocate one group only it has three cases :
// i) if allocate block2 then we cannot allocate block1 and block3 because they are overlap with block2
// ii) we can allocate only block2 if in it there is no seat reserved and if any seat in block3 is reserved and cannot take block2 because it overlap with block1
// iii) we can allocate only block3 if in it there is no seat reserved and if any seat in block2 is reserved and cannot take block2 because it overlap with block1

// 3. we cannot allocate block because in there is any one seat reserved in each block

// so we have 3 cases either we can allocate 2 block,either 1 block, or either none block

// so we have to process only rows that appear in the reservedSeats array that is given in input because in that rows we have to check for seats is it reserved or not and for other rows that are not in reservesSeats array then we can always allocate seats for two groups because in that row no seat is reserved so we can allocate two groups in that row because we want maximum number of groups that can be allocate

// now my solution that I think
// it give time limit exceed because I process with each row from 1 to n
// but we have to process only those rows that are in reservedSeats array because for other row we can simple say that they allocate two groups
// we are looping from 1 to n

// This is the biggest issue:

// for(int i=1;i<=n;i++)

// Since n can be as large as 10^9, this can take O(n) time.

// But reservedSeats.length <= 10^4, so we should only process the rows that actually have reservations.

// For example, if:

// n = 1000000000

// and only row 500 has a reservation, your loop still checks 1 billion rows.

// Instead:

// Rows present in reservedSeats → calculate normally.
// Rows not present → each can always fit 2 groups.
// Number of completely empty rows = n - number_of_reserved_rows.

// and there are one more bug in my solution

// Our block checking logic is more complicated than necessary

// There are only three possible blocks:

// A = 2 3 4 5
// B = 4 5 6 7
// C = 6 7 8 9

// Notice:

// A and C don't overlap, so if both are available → 2 groups.
// If A or C is available → at least 1 group.
// If neither A nor C is available, B might still be available → 1 group.
// Otherwise → 0 groups.

// So for each reserved row:

// if (A && C)
//     ans += 2;
// else if (A || B || C)
//     ans += 1;

// That's enough.

// Your code also has a small confusing bug

// You write:

// if((seats[6]!=1&&seats[7]!=1&&seats[8]!=1&&seats[9]!=1)&&(block2==0)){

// but block2 is still 0 at this point. You probably intended to check block1 or simply not need that condition at all.

// so my solution is close, but there two important problems in my implementation.

// so given below solution has some problem, I mentioned it above

// int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
// {
//   int maxGroup = 0;
//   map<int, vector<int>> mpp;
//   for (int i = 0; i < reservedSeats.size(); i++)
//   {
//     int row = reservedSeats[i][0];
//     int seat = reservedSeats[i][1];
//     mpp[row].push_back(seat);
//   }
//   for (int i = 1; i <= n; i++)
//   {
//     int row = i;
//     if (!mpp.count(row))
//     {
//       maxGroup += 2;
//     }
//     else
//     {
//       int block1 = 0, block2 = 0, block3 = 0;
//       vector<int> seat = mpp[row];
//       vector<int> seats(10 + 1, 0);
//       for (int i = 0; i < seat.size(); i++)
//       {
//         seats[seat[i]] = 1;
//       }
//       if ((seats[2] != 1 && seats[3] != 1 && seats[4] != 1 && seats[5] != 1) && (block2 == 0))
//       {
//         maxGroup += 1;
//         block1 = 1;
//       }
//       if ((seats[6] != 1 && seats[7] != 1 && seats[8] != 1 && seats[9] != 1) && (block2 == 0))
//       {
//         maxGroup += 1;
//         block3 = 1;
//       }
//       if ((block1 == 0 && block3 == 0) && (seats[4] != 1 && seats[5] != 1 && seats[6] != 1 && seats[7] != 1))
//       {
//         block2 = 1;
//         maxGroup += 1;
//       }
//     }
//   }
//   return maxGroup;
// }

// correct version of above code

// t.c-
// let m=reservedSeats.size()
// t.c-O(mlogm) because we processed only reserved seats and we use ordered map so it takes logm for each reserved seat
// s.c-O(n) in worst case if each row has reserves seat+O(11) for resereved array

int maxNumberOfFamilies(int n, vector<vector<int>> &reservedseats)
{

  // n is the total number of rows

  // we use map to store reserved seats of the row
  // so we store<row,seats> in map where for seats I used vector becuase for one row there can be many reserved seats
  map<int, vector<int>> mpp;
  // store reserved seats row-wise
  for (auto &x : reservedseats)
  {
    mpp[x[0]].push_back(x[1]); // means row={seats vector}
  }
  int maxGroup = 0; // max family that I can assigned
  // we process only rows that are reserved and we store that rows in map
  // rows having at least one reserved seat
  for (auto it : mpp)
  {
    vector<int> seats = it.second;
    // here row is row that having reserved seat
    // we know in each row there are 10 seats from 1 to 10 so we take array of size 11 because it is 0 based indexing
    vector<int> reserved(11, 0); // 0 represent that seat is not reserved while 1 represent that seat is reserved
    // so for getting reserevd seat in that row we traverse seats vector
    for (int seat : seats)
    {
      reserved[seat] = 1; // means it is reserved seat
    }
    // we check for three block
    bool left = (reserved[2] == 0 && reserved[3] == 0 && reserved[4] == 0 && reserved[5] == 0);   // it means first block has no reserved seat
    bool middle = (reserved[4] == 0 && reserved[5] == 0 && reserved[6] == 0 && reserved[7] == 0); // it means second block has no reserved seat
    bool right = (reserved[6] == 0 && reserved[7] == 0 && reserved[8] == 0 && reserved[9] == 0);  // it means third block has no reserved seat

    // we can allocate two groups when left & right are true in that row because they don't share any seats , so we can put two groups in the same row.
    if (left && right)
      maxGroup += 2;
    // we can allocate only one group either one of is true in that row
    else if (left || middle || right)
      maxGroup += 1;
    // for none group allocate we don't have to write because it add 0 in ans
  }

  // now we allocate two group(because we want maximum) for those rows that doesnot have any reserved seat
  maxGroup += (n - mpp.size()) * 2;
  return maxGroup;
}

int main()
{
  int n;
  cin >> n; // number of rows
  int m;
  cin >> m;
  vector<vector<int>> reservedSeats(m, vector<int>(2));
  for (int i = 0; i < m; i++)
  {
    cin >> reservedSeats[i][0] >> reservedSeats[i][1];
  }
  cout << maxNumberOfFamilies(n, reservedSeats);
  return 0;
}