 else 
     {
         int n;
         while(!estvide(c))
         {
           
            n = 0;
            while (!estvide(c) && !estvide(c->suiv) && c->done == c->suiv->done)
            {
                pre = c;
                suiv = c->suiv;
                n++;
                c =supp_position_bis(c);
            }
            if(c->done==l->done)
               {
                l = inserer_tete(l, n + 1);
                c = l->suiv;
               } 
            else if(c->done!=c->suiv->done)
            {
                c = inserer_position_actu(c,n+1);
                c = c->suiv;
            }
         }
         