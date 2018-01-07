// https://www.hackerrank.com/challenges/2d-array
import Foundation

let N = 6
var A = [[Int]]()

for i in 0..<N {
    let ints = readLine()!.componentsSeparatedByString(" ").map { Int($0)! }
    A.append(ints)
}

var val = 0, maximum = Int.min

for i in 0...3 {
    for j in 0...3 {
        val = A[i][j] + A[i][j+1] + A[i][j+2]
        val += A[i+1][j+1] + A[i+2][j]
        val += A[i+2][j+1] + A[i+2][j+2]
        maximum = max(val, maximum)
    }
}

print(maximum)