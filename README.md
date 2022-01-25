# The task description
There are n cities, and for any cities u,v (u does not equal to v) , there are exactly one road which connect u and v.  
Obviously, there are n(n-1)/2 roads. Of course, the distances among these roads are not same.  
You are given the n, and the distances of the roads. You need to find the shortest route, which has a length of n, and each city occured exactly one time in the route.  
The distance of the route is the time you need to take to visit the cities in order.  

# Algorithm one : Brute Force
You can enumerate all of the permutations of 1 ~ n as the route, and caculate the distance of the route in O(n) time.  
You should record the mininum distance and the matching route while doing that.  
Finally print the things you recorded.  
The complexity : O(n! * n).  

# Algorithm two : Status Compression DP   
Let the DP status be : dp[x][S] (x is in the set S) , which means you have already visited the cities in the set S, and the last city you visited is the x-th city.  
Transfer : for any dp[x][S], enumerate city y which is not contained in set S. and transfer from dp[x][S] to dp[y][S + {y}] . In detail, let interger v be dp[x][S] + w[x][y], which w[x][y] is the distance of the road between x and y. And if v is smaller than dp[y][S + {y}], let dp[y][S + {y}] be v.  
The transfer order could simply be : enumerate S from 1 to 2^n - 1 (after compressing set S to interger S), and inside enumerate the x (note that x should be contained in S) .  
To print the route, one way is for any (x, S) , record which city does f[x][S] transfered from, that is, which y satisfy f[y][S - {x}] + w[x][y] = f[x][S] (note that if there are multiple y, that means there are multiple routes, you can record any).  
The complexity : O(2^n * n^2) , which is faster than the Brute Force.  
