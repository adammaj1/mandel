mandel it is unofficial repository related with: [Mandel: software for real and complex dynamics by Wolf Jung](https://mndynamics.com/indexp.html)

Here you will find
* c++ console programs which explain algorithms used in the program mandel

See also [wikibooks](https://en.wikibooks.org/wiki/Fractals/mandel)

# Programs

## wake

code 
* [wake.cpp](./src/wake/wake.cpp)







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

```
mkdir images
git add *.png
git mv  *.png ./png
git commit -m "move"
git push -u origin main

```

then link the images:

```
![](./png/n.png "description of n.png image") 
```
to overwrite

```
git mv -f 
```

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


