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

	// Print
	fmt.Print("hello, ")
	fmt.Print("world! \n")

	fmt.Println()

	// Println
	fmt.Println("hello, world! ")
	fmt.Println("goodbye, cruel world! ")

	fmt.Println()

	// Printf
	blue := "blue"
	yelo := "yelo"
	fmt.Print("The sky is ", blue, ". The field is ", yelo, ". \n")
	fmt.Printf("The sky is %v. The field is %v. \n", blue, yelo)
	fmt.Printf("The sky is %q. The field is %q. \n", blue, yelo)
	fmt.Printf("The sky is %T. The field is %T. \n", blue, yelo)

	fmt.Println()

	// float
	m := 196.883
	fmt.Printf("The Monster acts non-trivially on %0.3f dimensions. \n", m)

	fmt.Println()

	// Sprintf
	sentence := fmt.Sprintf("The sky is %v. \n", blue)
	fmt.Println(sentence)
}
