package testLogic

fun main() {
    print("Input number : ")
    val n = readLine()!!.toInt()
    var temp1 = 0
    var temp2 = 1


    for (i in 1..n){
        print("$temp1,")
        val sum = temp1 + temp2
        temp1 = temp2
        temp2 = sum
    }
}