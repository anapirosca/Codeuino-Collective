library(tidyverse)
dat.f <- list.files(pattern = "couch|active.csv") 

dat.l <- list() 

for(i in dat.f){
  met.dat<- unlist(strsplit(i,"_")) 
  who <- met.dat[1] 
  activity <- gsub(".csv","",met.dat[2]) 
  dat.l[[i]]<- read_csv(i)%>%
    mutate(who=who,activity=activity) 
}
dat <- do.call(rbind,dat.l) 

dat%>%
  ggplot()+geom_boxplot(aes(x=activity,y=degC))+facet_grid(.~who)