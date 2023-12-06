# __Mar Updates__

Data   | Task
:----- | :---
mar 16 | module 9 : fi. ex01 ex02
&#8203;| _{reading}_ : allocator explained: [@](https://zhuanlan.zhihu.com/p/185611161) [@](https://blog.csdn.net/JMW1407/article/details/106868553) [@](https://www.cnblogs.com/simonkly/p/7819122.html) [@](https://www.jianshu.com/p/d7be8a1d9010) [@](https://learn.microsoft.com/zh-cn/cpp/standard-library/allocator-class?view=msvc-170) [@](http://llllkkkk.github.io/2014/05/01/allocator-/) [@](https://cloud.tencent.com/developer/article/1007465)
&#8203;| [rebind](https://www.genban.org/ask/c/36708.html)
mar 15 | map : bug identified & fixed, rbt::upper_bound
&#8203;| fixed small bug in operator ==, map hpp
mar 14 | map : const pair bug
&#8203;| need main & tester
mar 13 | vector : fix 802/804 disparity in insert
&#8203;| sandbox : enable_if 
&#8203;| map : now compiles, hpp empty
mar 12 | rabbit : tpp now hosts private _func
&#8203;| type punning sandbox
mar 11 | vector : cleanup while loop
&#8203;| sanbox : continue map
mar 10 | vector : fixed resize by m_next_size
&#8203;| ~~vector : buggy awesome test in range constr~~
mar 9  | vector : fixed mazoise copy-swap
mar 8  | vector : fixed mazoise resize & insert

<!--
![](https://i.imgur.com/tJx6k1V.jpg)
-->


# _Resources_

Very good explanation from [paulahemsi](https://github.com/paulahemsi/ft_containers#Friend_keyword)

BST: Problems & Interview Questions [___List___](https://medium.com/techie-delight/binary-search-tree-bst-practice-problems-and-interview-questions-ea13a6731098)

___throw( ) vs. noexcept___ 
- _def._ - throw() is just an alias for noexcept(true)
- throw in function signature [bikulov](https://bikulov.org/blog/2013/11/23/throw-in-function-signature-in-c-/)
- Exception specifications [IBM](https://www.ibm.com/docs/en/zos/2.3.0?topic=only-exception-specifications-c)
- simple samples ons [rollbar](https://rollbar.com/blog/error-exceptions-in-c/#:~:text=An%20exception%20in%20C%2B%2B%20is,immediately%20after%20the%20try%20block.)

___std::vector::operator == (___ 
- _def._ - The C++ function `std::vector::operator ==` first checks the size of both container, if sizes are same then it compares elements sequentially and comparison stops at first mismatch.

___What is wchar_t?___
- idem.


___enable_if___
- [cppreference](https://en.cppreference.com/w/cpp/types/enable_if)
- What is std::enable_if and how to use it - [@@](https://medium.com/@sidbhasin82/c-templates-what-is-std-enable-if-and-how-to-use-it-fd76d3abbabe)
- _def._ - If `B` is `true`, `std::enable_if` has a public member typedef `type`, equal to `T`; otherwise, there is no member typedef
- _type def._ - either `T` or no such member, depending on the value of `B`

```c
// c++ 11 . for ft_containers
template<bool B, class T = void>
struct enable_if;

// c++ 14
template<bool B, class T = void>
using enable_if_t = typename enable_if<B, T>::type;
```



___is_integral___
- what are type traits in C - [HERE](https://dev.to/sandordargo/what-are-type-traits-in-c-18j5) 
- type_traits - [HERE](https://cplusplus.com/reference/type_traits/is_integral/?kw=is_integral)
- type_traits/const - [HERE](https://cplusplus.com/reference/type_traits/integral_constant)\
(is_integral dep of integral_constant) 
- sfinae & enable_if - [eli](https://eli.thegreenplace.net/2014/sfinae-and-enable_if)
- sfinae [h-deb.clg.qc.ca](https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/SFINAE.html)

___is_integral AND the `-pedantic` flag___ 
- _def._ - excessively concerned with minor details or rules; overscrupulous.
- [source](http://wrigstad.com/ioopm/compiling.html#:~:text=The%20%2Dpedantic%20flag%20turns%20on,do%20not%20follow%20ISO%20C%2B.) :: `-pedantic` turns on warnings demanded by strict ISO C and reject all programs that use forbidden extensions, and some other programs that do not follow ISO C+

```c
// template<>
// struct is_integral<long long int> : public true_type {};
/// 
/// C++98 doesnt support long long with -pedantic

// template<>
// struct is_integral<unsigned long long int> : public true_type {};
/// 
/// C++98 doesnt support long long with -pedantic
```


___C++ named requirements___
- BinaryPredicate \
... [cppreference](https://en.cppreference.com/w/cpp/named_req/BinaryPredicate)
  - STL sort() function, BinaryPredicate - [stof](https://stackoverflow.com/questions/7372132/c-stl-sort-function-binary-predicate)
- Compare \
... [cppreference](https://en.cppreference.com/w/cpp/named_req/Compare)


___BST and algorithms___

- Introduction to Algorithms - 3th [ed.](https://edutechlearners.com/download/Introduction_to_algorithms-3rd%20Edition.pdf) \
... deletion algorithm : _cf. page 315_
- ___Binary Search Tree___ - insert, [etc.](https://www.cs.dartmouth.edu/~thc/cs10/lectures/0428/0428.html)
- ___Red Black Tree___ \
... Pseudocode - [programiz](https://www.programiz.com/dsa/red-black-tree) \
... Python impl. - [boot.dev](https://blog.boot.dev/python/red-black-tree-python) \
... Expl. & impl. - [LMU](https://cs.lmu.edu/~ray/notes/redblacktrees) \
... Visualizer - [visualizer](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html) \
... Java impl. - [JAVA](https://www.happycoders.eu/algorithms/red-black-tree-java)
- INTRO : [intro](https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/?ref=gcse)
- INSERT : C [implementation](https://www.geeksforgeeks.org/c-program-red-black-tree-insertion)
- INSERT : [programiz](https://www.programiz.com/dsa/insertion-in-a-red-black-tree)
- ROTATE : [data structure](https://www.codesdope.com/course/data-structures-red-black-trees-insertion)
- ERASE : [delete](https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2)
- REBIND : [stof](https://stackoverflow.com/questions/14148756/what-does-template-rebind-do)




___Iterators___

- libstdc++ api - [stl_iterator.h](https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01052_source.html)
- Implement stl style iterators & avoid common pitfalls \
... std::tag, etc. [HERE](https://stackoverflow.com/questions/8054273/how-to-implement-an-stl-style-iterator-and-avoid-common-pitfalls)
- Define Iterators for Containers - [HERE](https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html)
- Tag dispatching - [HERE](https://www.fluentcpp.com/2018/04/27/tag-dispatching)
- Iterator Traits - [HERE](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits)
- iterators on `cplusplus.com` \
... iterator - [HERE](https://m.cplusplus.com/reference/iterator/iterator) \
... traits - [HERE](https://m.cplusplus.com/reference/iterator/iterator_traits)\
... reverse_it - [HERE](https://m.cplusplus.com/reference/iterator/reverse_iterator)\
... random [ ] - [HERE](https://m.cplusplus.com/reference/iterator/RandomAccessIterator)

>> ![](https://i.imgur.com/7XeM70S.png)


___General___

- C++ ISO 14882 - [ISO](https://kaltofen.math.ncsu.edu/courses/Languages/C++Examples/iso14882.pdf)
- Comprendre ___enable_if___ - [FR.](https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html)
- Custom STL-Like Containers and Iterators - [HERE](https://web.stanford.edu/class/cs107l/handouts/04-Custom-Iterators.pdf)
- ___SFINAE___ \
... Comprendre ___SFINAE___ (Substitution Failure is not an Error) - [FR.](https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/SFINAE.html) \
... Understand ___SFINAE___ - [Lecture 1](https://www.fluentcpp.com/2018/05/15/make-sfinae-pretty-1-what-value-sfinae-brings-to-code) \
... Understand ___SFINAE___ - [Lecture 1](https://www.fluentcpp.com/2018/05/18/make-sfinae-pretty-2-hidden-beauty-sfinae) 
... SFINAE en francais - [moins](https://www.developpez.com/actu/94611/SFINAE-Interlude-moins-Cplusplus-avance-exemple-d-implementation)
- Containers library \
... 🟢 Super Useful - [containers](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2011/n3242.pdf#page=731&zoom=100,96,712)\
... Chap. 11 : memory & vector example - [Vec](https://tfetimes.com/wp-content/uploads/2015/11/Accelerated_C-_Practical_Programming_by_Example_-_Andrew_Koenig_Barbara_E._Moo_-_Addison-Wesley_-_2000.pdf#page=250) \
... implementation specific size_type - [size_type](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2011/n3242.pdf#page=789&zoom=100,96,712)
- most readable STL implementation by Alexander Stepanov & Meng Lee \
... [stof](https://stackoverflow.com/questions/2127612/is-there-a-readable-implementation-of-the-stl) \
... [butler](http://stepanovpapers.com/butler.hpl.hp/stl/stl)
- Set impl. at GCC official github \
... [gcc mirror](https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/bits/stl_set.h)




___Stack___
- [cpluspluc](https://cplusplus.com/reference/stack/stack/?kw=stack) \
... page 181, ISO 1998



# _Rules_


```c
/**
 *  Rb tree rules
 * 
 *  1. a node is either red or black
 *  2. the root and leaves (NIL) are black
 *  3. if a node is red, then its children are black
 *  4. all paths from a node to its NIL descendants
 * 		contain the same number of black nodes
 * 
 *           8                            8
 *         /   \                        /   \
 *        /     \                      /     \
 *       5       15                   B        R               
 * 	/ \     /   \                / \     /   \
 *    nil nil  12     19           nil nil  B      B               
 *            /  \   /   \                 / \    / \
 *          9    13 nil   23             R    R  nil R    
 *         /  \  / \     /  \          /  \   / \    / \
 *      nil nil nil nil nil nil     nil nil nil nil nil nil
 *  
 * Notes:
 *    The longest path (root to farthest NIL) is no more
 *  than twice the length of shortest path (root to nearest NIL)
 *   - SHortest path: all black nodes
 *   - Longest path: alernating red and black
 *
 */
```

# _How to rotate_

```c
/*      y   right rotate     x
/      / \  ------------>   / \ 
/     x	  c                a   y 
/    / \     left rotate      / \ 
/   a   b   <------------    b   c
*/
```


# __Feb Updates__

![](https://i.imgur.com/3znf2g8.jpg)



# _Resources_



[@](https://m.cplusplus.com/reference/iterator/iterator) cplusplus/iterator  
[@](https://m.cplusplus.com/reference/iterator/iterator_traits) cplusplus/iterator_traits  \
[@](https://m.cplusplus.com/reference/iterator/RandomAccessIterator) cplusplus/RandomAccessIter  

[@](https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01052_source.html) gcc.gnu.stl_iterator.h  \
[@](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits) iterator_traits w/ distance() example 





# _To know_

Iterator traits
Member type | Definition
:-- | :--
difference_type | Iter::difference_type
value_type | Iter::value_type
pointer | Iter::pointer
reference | Iter::reference
iterator_category | Iter::iterator_category

5 main types of iterators
- Random-access iterators 
- Bidirectional iterator
- Forward iterator 
- Input iterators
- Output iterator 

lvalue \
rvalue

# _Things to learn_

```
std::iterator_traits
std::reverse_iterator
std::enable_if	{c++11}
std::is_integral
std::pair
std::make_pair
std::equal
std::lexicographical_compare
```

# _Red black tree_
- principle
- implementation




# _Stack_
\<cstddef> : what's inside

what is 2nd param: `typename Container = vector<T>`
- `template<typename T, typename Container = vector<T>>`

explicit
```
public: 
explicit 
stack(container_type const& c = container_type()) : c(c) 
{}
```

friend in Non-member fn overloads
- `friend bool operator == (stack const & l, stack const & r)`

container_type
- protected: container_type c;



# _Pair (unrel. to stack/vector yet ez to do)_
todolist
- class pair only has public mems
- occf
  - beware of copy constr
- operators == != < <= > >=
- make_pair
  - fn: 
`templ<typename X,typename Y> pair<X,Y> make_pair(X x, Y y) -> pair<X, Y>(x, y)`







# _Vector_
what is 2nd param: `typename Allocator = std::allocator<T>`
- template<typename T, typename Allocator = std::allocator<T>>



# _vector_iterator - (Virtual Class)_
\<iterator> : what's inside

std::random_access_iterator_tag
```
public: 
typedef
  std::random_access_iterator_tag  iterator_catorgory
```

std::ptrdiff_t
```
public:
typedef
  std::ptrdiff_t	difference_type
```

explicit
```
public:

explicit vector_iterator(pointer ptr) : m_ptr(ptr) {
}

virtual ~vector_iterator(void) {
}
```



# _vector_const_iterator - (Virtual Class)_
explicit
```
public:

explicit vector_const_iterator(pointer ptr) : m_ptr(ptr){
}

virtual ~vector_const_iterator(void) {
}
```



