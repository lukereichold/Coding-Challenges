// https://www.hackerrank.com/challenges/angry-professor
import Foundation

let T = Int(readLine()!)!

for _ in 1...T {
    let line1 = readLine()!.componentsSeparatedByString(" ").map { Int($0) }
    let K = line1.last!

    let arrivals = readLine()!.componentsSeparatedByString(" ").map { Int($0) }
    let cancelled : Bool = arrivals.filter({$0 <= 0}).count < K

    if cancelled {
        print("YES")
    } else {
        print("NO")
    }
}