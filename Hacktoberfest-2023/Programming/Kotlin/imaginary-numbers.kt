class Complex(
    private val a: Double,
    private val b: Double,
) {
    operator fun plus(other: Complex): Complex {
        return Complex(a + other.a, b + other.b)
    }
    
    operator fun minus(other: Complex): Complex {
        return Complex(a - other.a, b - other.b)
    }
    
    fun print() {
        println("$a + (${b}i)")
    }
}

fun main() {
    val a = Complex(3.0,2.0)
    val b = Complex(1.0,1.0)
    a.print()
    b.print()
    val sum = a + b
    val diff = a - b
   	sum.print()
    diff.print()
}