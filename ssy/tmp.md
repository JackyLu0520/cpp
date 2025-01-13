$$
dp_{i,l,r}=[a_{i,l-1}=a_{i,r}]\sum_{x=1}^{l}\sum_{y=r}^{m}dp_{i-1,x,y}
$$

$$
dp_{1,l,r}=[a_{1,l-1}=a_{1,r}]
$$

$$
s_{l,r}=\sum_{i=1}^{l}\sum_{j=1}^{r}dp_{cur,i,j}=s_{l-1,r}+s_{l,r-1}-s_{l-1,r-1}+dp_{cur,i,j}
$$

$$
dp_{i,l,r}=[a_{i,l-1}=a_{i,r}](s_{l,m}-s_{l,r-1})
$$
