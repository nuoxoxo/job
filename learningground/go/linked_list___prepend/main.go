package main
import "fmt"

const (
	noc	= "\033[0m"
	color1	= "\033[0;33m"
	color2	= "\033[0;36m"
)

type node struct {
	data	int
	next	*node
}

type linked_list struct {
	head	*node
	size	int
}


// (l *linked_list) is the pointer receiver
func (lst *linked_list) prepend (n *node) {
	temp := lst.head
	lst.head = n
	lst.head.next = temp
	lst.size++
}

// non-member func
func printll (lst linked_list) {
	fmt.Println(color1, "\nnon-member printer:", noc, lst)
	p := lst.head
	for p != nil {
		fmt.Println(p.data, "-", p)
		p = p.next
	}
	fmt.Println("(end)")
}

// (l linked_list) : the value receiver
func (lst linked_list) m_printll () {
	fmt.Println(color2, "\nmember printer:", noc, lst)
	p := lst.head
	for p != nil {
		fmt.Println(p.data, "-", p)
		p = p.next
	}
	fmt.Println("(end) ")
}

func main() {
	L := linked_list {}
	a1 := & node { data: 83 }
	a2 := & node { data: 68 }
	a3 := & node { data: 19 }
	L.prepend(a1)
	L.prepend(a2)
	L.prepend(a3)

	fmt.Print("address of node 3: \n\t")
	fmt.Println(L)

	fmt.Printf("head.data: \n\t%d \n", L.head.data)

	printll(L)
	L.m_printll()
}
