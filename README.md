mandel it is unofficial repository related with: [Mandel: software for real and complex dynamics by Wolf Jung](https://mndynamics.com/indexp.html)

Here you will find c++ console programs which
* explain algorithms used in the program mandel
* [Minimal reproducible example](https://en.wikipedia.org/wiki/Minimal_reproducible_example)

See also [wikibooks](https://en.wikibooks.org/wiki/Fractals/mandel)

# Programs

## wake

Description
* [wikibooks](https://en.wikibooks.org/wiki/Fractals/mandel#Wake)

code: [wake.cpp](./src/wake/wake.cpp)




to compile :

```g++ w.cpp -Wall -lm```

to run

```./a.out```


example session: 

```Determine the wake of a limb at the main cardioid of Mandelbrot set. 
Enter a fraction  k/r  for the rotation number, in lowest terms, with  1 <= k < r < 64 
 Enter numerator of the rotation number, it is integer  1 <= k < 64 :  
1
Enter the denominator of the rotation number, it is integer 1 <= r < 64 :  
3
The rotation number is 1/3
The 1/3 wake of the main cardioid is bounded by the parameter rays with the angles :
1/7 and 2/7
The root point of wake is c = -0.125 ; 0.649519052838329:
The fixed point alfa is z = -0.25 ; 0.433012701892219:
```

In the result from the program mandel 5.19 for input 1/3 is different: 

```The 1/3-wake of the main cardioid is
bounded by the parameter rays with the angles
1/7  or  p001  and
2/7  or  p010 .
Do you want to draw the rays and to shift c
to the center of the satellite component?
```



# Git


```
   git add README.md
   git commit -m "first commit"
   git branch -M main
   git remote add origin git@github.com:adammaj1/mandel.git
   git push -u origin main
```



Subdirectory
---------------

```mkdir images
git add *.png
git mv  *.png ./png
git commit -m "move"
git push -u origin main```

then link the images:

```![](./png/n.png "description of n.png image") ```
to overwrite

```git mv -f ```

local repo : 
--------------

~/mandel


License
------------------
File LICENSE must be in main repo directory to be read by github


Github
* [GitHub Flavored Markdown Spec](https://github.github.com/gfm/)
* [md cheat sheet](http://mdcheatsheet.com/)
* [CommonMark Spec](https://spec.commonmark.org)
* [Markdown parser ](https://markdown-it.github.io/)


Math equation inside README.md
* $\sqrt{3x-1}+(1+x)^2$


