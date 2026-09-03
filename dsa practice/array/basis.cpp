// declare array inside int main like int arr[6] place memory of block 6 with garbage value but
// declare array globally i.e. outside of int main place memory of size 6 but with value 0
// maximum size of array is 10^6 inside int main
// globally maximum size is 10^7
// array stored in contiguous memory allocation like arr[0] stored at x then arr[1] stored at x+1 and so on

// 🧠 Key Takeaway

// ❌ Never trust external n
// ✅ Always use arr.size()
// ❌ Out-of-bounds access = Undefined Behavior