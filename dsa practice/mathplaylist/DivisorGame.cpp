// Alice and Bob take turns playing a game, with Alice starting first.

// Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

// Choosing any integer x with 0 < x < n and n % x == 0.
// Replacing the number n on the chalkboard with n - x.
// Also, if a player cannot make a move, they lose the game.

// Return true if and only if Alice wins the game, assuming both players play optimally.

// Example 1:

// Input: n = 2
// Output: true
// Explanation: Alice chooses 1, and Bob has no more moves.
// Example 2:

// Input: n = 3
// Output: false
// Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.

// Constraints:

// 1 <= n <= 1000

#include <bits/stdc++.h>
using namespace std;

// first understand the game:
// Suppose: n=6
// Alice can choose any x such that:
// 0<x<6 and 6%x==0

// possible x values are: 1,2,3
// then the number becomes: 6-x
// for example, Alcie chooses x=2: n=6-2=4
// now Bob plays with n=4

// The important thing is: A player loses if there is no valid divisor to choose.

// Base cases:
// When n=1
// we need: 0<x<1
// There is no integer satisfying this.
// Therefore Alice has no move.

// n=1
// Alice cannot move
// Alice loses
// So: 1 -> lose , alice lose

// n=2
// possible x: 0<x<2
// only x=1
// and: n%x==0 so 2%1==0
// So Alice can play:
// n=n-x=2-1=1
// Now bob has: n=1
// Bob cannot move, so Bob loses.

// therefore: 2 -> win, alice win

// So our starting pattern is:
// n=1 : lose
// n=2 : win

// Base case:
// When N = 1, Alice loses; When N = 2, Alice wins.

// Inductive step:
// Hypothesis: When N = 2k-1, Alice loses; When N = 2k, Alice wins. (For any k >= 1)

// What does the induction hypothesis mean?
// it basically says:
// Odd number: Alice loses
// Even number: Alice wins

// But instead of saying it for every number at once, induction assumes that the pattern is already true up to some point.

// example, suppose: k=3
// then: 2k-1=5 and 2k=6
// the hypothesis says:
// 5: lose
// 6: win

// Now we need to prove:
// 7: lose
// 8:win
// That's the inductive step.

// Proof: When N = 2k+1, Alice has to subtract an odd from N then Bob wins due to the remaining even number no greater than 2k;
// When N = 2k+2, Alice can subtract 1 from N then Bob loses due to the remaining N equal to 2k+1.

// Proving an odd number is losing
// Consider:
// n=2k+1,  this is an odd number
// The proof says: Alice has to subtract an odd from n.

// Why?
// Because every divisor of an odd number is odd.
// we say this because we also wants n%x==0

// for example:
// 9 : divisors smaller than 9: 1,3
// 15 : 1,3,5
// 21: 1,3,7
// All are odd.

// So when Alice plays:
// odd-odd=even
// Therefore after Alice's move, the number becomes even.

// example: n=7
// Alice can choose: x=1
// 7-1=6
// or: 7-7 not allowed because x<n
// so: n=n-x=7-1=6
// Bob receives an even number.

// Why does Bob win after receiving that even number?
// The new number is : n-x
// where: n=2k+1 and x>0
// Therefore: n-x < 2k+1
// Since it is even, it must be one of:
// 2,4,6,....,2k
// The induction hypothesis says: 2,4,6,...,2k are winning positions for the player whose turn it is.

// And whose turn is it?
// Bob's turn.
// Therefore Bob receives a winning position.

// So:
// Alice starts with odd n -> Alice must subtract odd x -> odd-odd=even -> Bob gets an even number <= 2k -> Even positions are winning -> Bob wins
// Therefore: odd n : Alice loses

// Now proves an even number is winning
// Consider: n=2k+2, this is even
// Alice can always choose: x=1
// Why is this allowed? because 0<1<n and n%1==0

// So Alice does: 2k+2 subtract 1 gets 2k+1
// Now Bob receives: 2k+1 which is odd.
// From the previous part, we proved: odd-> losing position. Therefore Bob loses.

// and we know both play optimally.

// So: even n : Alice wins.

// Put both parts together

// We have proved:

// if n is odd: Alice is forced to make: odd-odd=even
// So Bob receives an even winning position.
// Therefore: odd n : Alice loses

// if n is even: Alice can choose: x=1 and make: even-1=odd
// Bob receives an odd losing position.
// Therefore: even n : Alice Wins.

// In conclusion, Alice wins the game when N is even; Alice loses the game when N is odd.

// the intuition to remember:

// Think of odd numbers as losing positions and even numbers as winning positions:

// Even -> Alice subtracts 1 -> become odd -> Bob gets losing position -> Alice wins

// while:

// odd -> Alice must subtract and odd divisor -> become even -> Bob gets winning position -> Alice loses

// t.c-O(1)
// s.c-O(1)
bool divisorGame(int n)
{
  // When n is even Alice wins, else when n is odd Bob wins.
  return n % 2 == 0;
}

int main()
{
  int n;
  cin >> n;
  cout << divisorGame(n);
  return 0;
}