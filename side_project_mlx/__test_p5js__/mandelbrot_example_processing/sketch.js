//#* ************************************************************************** *#
//#*                                                                            *#
//#*                            \\             #`#``                            *#
//#*                            ~\o o_       0 0\                               *#
//#*                            # \__)      (u  ); _  _                         *#
//#*                     # \# \#  #           \  \# \# \                        *#
//#*                    #(   . . )            (         )\                      *#
//#*                   #  \_____#              \_______#  \                     *#
//#*                       []  []               [[] [[]    *.                   *#
//#*                       []] []]              [[] [[]                         *#
//#*                                                                            *#
//#* ****************************************************************** .js *** *#

function setup() {
	createCanvas(1920, 1080)
	pixelDensity(1)
	noLoop()
}

function draw() {

	background(0)

	const	w = 4
	const	h = w * height / width
	const	xmin = -w / 2
	const	ymin = -h / 2

	loadPixels()

	const	maxiterations = 100
	const	xmax = xmin + w
	const	ymax = ymin + h
	const	dx = (xmax - xmin) / width
	const	dy = (ymax - ymin) / height

	let	y = ymin
	let	j = -1
	while (++j < height) {
		let	x = xmin - 1
		let	i = -1
    		while (++i < width) {
			let	a = x
			let	b = y
			let	n = 0
			while (n < maxiterations) {
				const	aa = a * a
				const	bb = b * b
				const	twoab = 2.0 * a * b
				a = aa - bb + x
				b = twoab + y
				if (dist(aa, bb, 0, 0) > 16) {
          				break
				}
				n++
			}
			const	pix = (i + j * width) * 4
			const	norm = map(n, 0, maxiterations, 0, 1)
			let	brightness = map(sqrt(norm), 0, 1, 0, 255)
			if (n == maxiterations) {
				brightness = 0
			} else {
				pixels[pix + 0] = brightness
				pixels[pix + 1] = brightness
				pixels[pix + 2] = 255
				pixels[pix + 3] = 200
			}
			x += dx
		}
		y += dy
	}
	updatePixels()
}

