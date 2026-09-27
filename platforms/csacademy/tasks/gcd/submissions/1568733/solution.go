package main

import "fmt"

func gcd(a, b int) int {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}

func main() {
    var a, b int
    fmt.Scanln(&a, &b)
    fmt.Println(gcd(a, b))
}