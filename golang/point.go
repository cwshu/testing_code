/* point.go
 *
 * test anonymous field inheritance, function overloading, and super
 *
 * refs:
 * - Constructors: http://www.golangpatterns.info/object-oriented/constructors
 * - Anonymous fields in structs - like object composition: http://golangtutorials.blogspot.tw/2011/06/anonymous-fields-in-structs-like-object.html
 * - Go by Example: Interfaces: https://gobyexample.com/interfaces
 */


package main

import "fmt"

type Point2d struct {
    x float32
    y float32
}

/*
func NewPoint2d(x float32, y float32) *Point2d {
    return &Point2d {
        x: x,
        y: y,
    }
}*/

func (p *Point2d) get_x() float32 {
    return p.x
}

func (p *Point2d) get_y() float32 {
    return p.y
}

type LatticePoint2d struct {
    Point2d
}

/*
func NewLatticePoint2d(p *Point2d) *LatticePoint2d {
    return &LatticePoint2d {
        Point2d {
            x: p.x,
            y: p.y,
        },
    }
}*/

func (p *LatticePoint2d) get_x() int {
    return int(p.Point2d.get_x())
}

func main() {
    p1 := Point2d{1.0, 2.0}
    p2 := Point2d{3.5, 4.0}
    p3 := LatticePoint2d{Point2d{p2.x, p2.y}}
    // p4 := NewLatticePoint2d(&p2)
    // var p5 *LatticePoint2d = NewLatticePoint2d(&p2)

    fmt.Println(p1.get_x())
    fmt.Println(p2.get_x())
    fmt.Println(p3.get_x())
    // fmt.Println(p4.get_x())
    // fmt.Println(p5.get_x())
}
