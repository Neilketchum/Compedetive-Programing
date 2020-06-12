// // The N (1 ≤ N ≤ 50,000) cows, conveniently numbered 1, 2, …, N, are trying to learn some 
// encryption algorithms. After studying a few examples, they have decided to make one of their
//  own! However, they are not very experienced at this, so their algorithm is very simple:

// // Each cow i is given a starting number Ci (0 ≤ Ci < 90,000,000), and then all the cows 
// perform the following process in parallel:

// // First, each cow finds the sum of the numbers of the other N-1 cows. After all cows are 
// finished, each cow replaces her number with the sum she computed. To avoid very large numbers, 
// the cows will keep track of their numbers modulo 98,765,431. They told Canmuu the moose about it in November; he
//  was quite impressed. Then one foggy Christmas Eve, Canmuu came to say:

// // "Your algorithm is too easy to break! You should repeat it T (1 ≤ T ≤ 1,414,213,562) times instead." Obviously, 
// the cows were very frustrated with having to perform so many repetitions of the same boring algorithm, so after 
// many hours of arguing, Canmuu and the cows reached a compromise: You are to calculate the numbers 
// after the encryption is performed!