
import Foundation

var levels = [0,0,0,0,0,0]
var minutes = 0
var timer = [0,0,0,0,0,0]


while minutes != 100{
    if timer[0] >= 3{
        timer[0] = 0
        levels[0] = levels[0] + (levels[1] * 2)
    }
    if timer[1] >= 60{
        timer[1] = 0
        levels[1] = levels[1] + (levels[2] * 2)
    }
    if timer[2] >= 360{
        timer[2] = 0
        levels[2] = levels[2] + (levels[3] * 1)
    }
    if timer[3] >= 1080{
        timer[3] = 0
        levels[3] = levels[3] + (levels[4] * 2)
    }
    if timer[4] >= 1800{
        timer[4] = 0
        levels[4] = levels[4] + (levels[5] * 2)
    }
    if timer[5] >= 2880{
        timer[5] = 0
        levels[5] += 1
    }
    
    minutes = minutes + 1
    for i in 0..<timer.count{
        timer[i] += 1
    }
}

for j in 0..<levels.count{
    print("Level " + j + " has " + levels[0] + " zombies!")
}
