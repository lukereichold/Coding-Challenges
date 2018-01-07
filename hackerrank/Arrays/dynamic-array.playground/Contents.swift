//: Playground - noun: a place where people can play

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let N = input[0], Q = input[1]

typealias Sequence = [Int]
var seqList = [Sequence](repeating: [], count: N)
var lastAnswer = 0

for _ in 0 ..< Q {
    let input = readLine()!.split(separator: " ").map { Int($0)! }
    let query = input[0], x = input[1], y = input[2]
    let index = (x ^ lastAnswer) % N

    if query == 1 {
        seqList[index].append(y)
    } else {
        let seq = seqList[index]
        lastAnswer = seq[y % seq.count]
        print(lastAnswer)
    }
}
