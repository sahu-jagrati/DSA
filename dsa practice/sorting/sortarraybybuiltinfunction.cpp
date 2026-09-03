// sort(nums+1,nums+n); is this correct

// yes, it can be correct — but only in specific cases 👍
// Let’s break it down simply.

// When it is correct

// This syntax is correct in C / C++ if nums is a raw array, not a vector.

// int nums[] = {5, 3, 1, 4, 2};
// int n = 5;

// sort(nums + 1, nums + n);

// 👉 This will sort from index 1 to index n-1
// So result becomes:

// 5 1 2 3 4

// (index 0 stays untouched)

// Why?

// nums + 1 → address of index 1

// nums + n → one past the last element (required by sort)

// When it is ❌ wrong

// If nums is a vector, then this is NOT correct:

// vector<int> nums;
// sort(nums + 1, nums + n); ❌

// Because vectors don’t support pointer arithmetic.

// Correct way for vector
// sort(nums.begin() + 1, nums.end());

// or if you want till n-1:

// sort(nums.begin() + 1, nums.begin() + n);