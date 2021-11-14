
# Table of Contents

1.  [Sequential container](#orgf70f8b0)
    1.  [Introduction](#orgc724a3f)
    2.  [Container operations](#org253b118)



<a id="orgf70f8b0"></a>

# Sequential container


<a id="orgc724a3f"></a>

## Introduction

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">container\attributes</th>
<th scope="col" class="org-left">flexible size</th>
<th scope="col" class="org-left">random access</th>
<th scope="col" class="org-left">insert/delete</th>
<th scope="col" class="org-left">note</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-left">vector</td>
<td class="org-left">yes</td>
<td class="org-left">yes</td>
<td class="org-left">back is fast</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">deque</td>
<td class="org-left">yes</td>
<td class="org-left">yes</td>
<td class="org-left">fast at front/back</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">list</td>
<td class="org-left">yes</td>
<td class="org-left">No , sequence access</td>
<td class="org-left">fast at any point</td>
<td class="org-left">bidirection</td>
</tr>


<tr>
<td class="org-left">forward<sub>list</sub></td>
<td class="org-left">yes</td>
<td class="org-left">yes</td>
<td class="org-left">fast at any point</td>
<td class="org-left">one direction</td>
</tr>


<tr>
<td class="org-left">array</td>
<td class="org-left">fixed size</td>
<td class="org-left">yes</td>
<td class="org-left">don&rsquo;t support</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">string</td>
<td class="org-left">yes</td>
<td class="org-left">yes</td>
<td class="org-left">back is fast</td>
<td class="org-left">special type of vector</td>
</tr>
</tbody>
</table>


<a id="org253b118"></a>

## Container operations

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">aliases type</th>
<th scope="col" class="org-left">properties</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-left">iterator</td>
<td class="org-left">type of the iterator for this container type</td>
</tr>


<tr>
<td class="org-left">const<sub>iterator</sub></td>
<td class="org-left">iterator type but can&rsquo;t change it&rsquo;s value</td>
</tr>


<tr>
<td class="org-left">size<sub>type</sub></td>
<td class="org-left">unsigned integral for size of container type</td>
</tr>


<tr>
<td class="org-left">difference<sub>type</sub></td>
<td class="org-left">signed integral big enough to hold distance between 2 iterator</td>
</tr>


<tr>
<td class="org-left">value<sub>type</sub></td>
<td class="org-left">Element type</td>
</tr>


<tr>
<td class="org-left">reference</td>
<td class="org-left">Element&rsquo;s lvalue type</td>
</tr>
</tbody>
</table>

        string s("abcdef");
        for (string::iterator it = s.begin(); it !=s.end(); ++it) {
           string::reference s = *it;
           s+=1;
        }
    
        for (string::iterator it=s.begin(); it!=s.end() ;++it) {
           string::const_reference s = *it;
            cout << s << endl;
        }
    
    └─[0] <> g++ test.cpp
    ┌─[longkl@longkl] - [~/working/cpp] - [2021-10-03 10:15:49]
    └─[0] <> ./a.out
    b
    c
    d
    e
    f
    g

abc

