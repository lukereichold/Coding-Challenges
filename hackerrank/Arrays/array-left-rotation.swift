import Foundation

let input = readLine()!.componentsSeparatedByString(" ").map { Int($0)! }
let N = input[0], shift = input[1]

var arr = readLine()!.componentsSeparatedByString(" ").map { Int($0)! }

let combined = arr + arr
let offset = N - shift

for i in shift..<(2*N - offset) {
    print(combined[i], terminator: " ")
}
