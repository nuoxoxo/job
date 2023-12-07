/* ************************************************************************** */
/*                                                                            */
/*                            \\             /`/``                            */
/*                            ~\o o_       0 0\                               */
/*                            / \__)      (u  ); _  _                         */
/*                     / \/ \/  /           \  \/ \/ \                        */
/*                    /(   . . )            (         )\                      */
/*                   /  \_____/              \_______/  \                     */
/*                       []  []               [[] [[]    *.                   */
/*                       []] []]              [[] [[]                         */
/*                                                                            */
/* ****************************************************************** .go *** */

package main

import "fmt"

func main() {

	// Arrays . len-fixed
	var a1 [3] int = [3] int {47, 59, 71}
	var a2 = [3] int {47, 59, 71}
	a3 := [3] int {47, 59, 71}
	fmt.Println("all arrays are the same: ", a1, a2, a3)

	fmt.Println("\narrays are len-fixed, cannot be appended")
	fmt.Println("slices are in-fact arrays\n")

	// Slices
	slc := []int {47, 59, 71}
	slc = append(slc, 196883)
	fmt.Println("append : \n", slc)
	fmt.Println("range[:3] : \n", slc[:3])
	fmt.Println("append : \n", append(slc, 4371))
}
