/*
{{Podświetl|js}}
<pre>

 * author: [[User:Piotr]]
 * license: BSD
// */

var pathway = {
   initialized: false,
   firstHeading: null,   // first heading element
   fHState: null, // true if firstHeading is short
   navVisible: null, // true if navigation is visible
   pagename: null,
   namespaces: {0: true}
};


// initialize patway
pathway.init = function()
{
   if ( this.initilized ) {
      return;
   }

   this.inititialized = true;
   if ( !pathway.namespaces[pageInfo.namespace] ) {
      return;
   }

   // shorten first heading
   if ( pageInfo.title != pageInfo.name && pageInfo.action != 'edit' && pageInfo.action != 'submit' ) {
      this.fHState = true;
      this.navVisible = false;
      this.firstHeading = document.getElementById("content").getElementsByTagName("h1")[0];
      var div = document.createElement("div");
      div.setAttribute("id", "pwFHButtonDiv");

      var but = document.createElement("a");
      but.setAttribute("id", "pwFHButton");
      but.href = "javascript:pathway.toggleFirstHeading()";
      but.appendChild(document.createTextNode("zwiń"));

      div.appendChild(document.createTextNode('['))
      div.appendChild(but);
      div.appendChild(document.createTextNode(']'))
      document.getElementById("content").insertBefore(div, this.firstHeading);
   }

   // show pathway
   this.navVisible = false;
   var contentSub = document.getElementById("contentSub");

   var contentDiv = document.createElement("div");
   contentDiv.setAttribute("id", "pwContent");

   contentSub.insertBefore(contentDiv, contentSub.firstChild);

   this.show(pageInfo.name);
   if ( this.firstHeading != null )
      this.toggleFirstHeading();
}

// show pathway
pathway.show = function(pagename)
{
   this.pagename = pagename;

   var content = document.getElementById("pwContent");
   // removing all children
   while (content.lastChild) {
      content.removeChild(e.lastChild);
   }

   var e = document.createElement("div");
   e.setAttribute("id", "pwPathway");

   // adding links (> book > chapter > section > etc. )
   var href = "";
   var i = 0;
   var j = pagename.indexOf('/');
   while (j != -1) {
      var lnk = document.createElement("a");
      lnk.appendChild(document.createTextNode(pagename.slice(i, j)));
      lnk.href = "http://pl.wikibooks.org/wiki/" + pagename.slice(0, j);

      e.appendChild(document.createTextNode(" > "));
      e.appendChild(lnk);

      i = j + 1;
      j = pagename.indexOf('/', i);
   }

   e.appendChild(document.createTextNode(" > "));
   e.appendChild(document.createTextNode(pagename.slice(i, pagename.length)));


   // button to show or hide navigation
   var navBut = document.createElement("a");
   navBut.setAttribute("id", "pwNavToggle");
   navBut.href = "javascript:pathway.toggleNavigation()";
   navBut.appendChild(document.createTextNode(" »"));
   e.appendChild(navBut);

   content.appendChild(e);

   // simple navigation
   var navDiv = document.createElement("div");
   navDiv.setAttribute("id", "pwNav");
   navDiv.style.display = "none";

   var input = document.createElement("input");
   input.setAttribute("id", "pwNavInput");
   input.type = "text";
   input.value = pageInfo.name;
   input.onkeyup = function(){pathway.updateNavigation()};

   var buttons = document.createElement("span");
   buttons.setAttribute("id", "pwNavButtons");
   buttons.appendChild(document.createTextNode(" "));

   var but = document.createElement("a");
   but.setAttribute("id", "pwNavGo");
   but.href = "http://pl.wikibooks.org/wiki/" + this.pagename;
   but.appendChild(document.createTextNode("Przejdź"));
   buttons.appendChild(but);

   buttons.appendChild(document.createTextNode(' | '));

   but = document.createElement("a");
   but.setAttribute("id", "pwNavEdit");
   but.href = "http://pl.wikibooks.org/w/index.php?action=edit&title=" + this.pagename;
   but.appendChild(document.createTextNode("Edytuj"));
   buttons.appendChild(but);

   navDiv.appendChild(input);
   navDiv.appendChild(buttons);
   content.appendChild(navDiv);
}

// lengthen or shorten first heading
pathway.toggleFirstHeading = function()
{
   var but = document.getElementById('pwFHButton');
   if ( this.fHState == 1 ) {
      this.fHState = 0;
      this.firstHeading.lastChild.data = pageInfo.title;
      but.firstChild.data = "rozwiń";
   } else {
      this.fHState = 1;
      this.firstHeading.lastChild.data = pageInfo.name;
      but.firstChild.data = "zwiń";
   }
}

// show or hide navigation
pathway.toggleNavigation = function()
{
   var nav = document.getElementById("pwNav");
   var but = document.getElementById("pwNavToggle");
   if ( this.navVisible ) {
      this.navVisible = false;
      nav.style.display = "none";
      but.firstChild.data = " »";
   } else {
      this.navVisible = true;
      nav.style.display = "block";
      but.firstChild.data = " «";
   }
}

// update navigation buttons
pathway.updateNavigation = function()
{
        var link = document.getElementById("pwNavInput").value;
        document.getElementById("pwNavGo").href = "http://pl.wikibooks.org/wiki/" + link;
        document.getElementById("pwNavEdit").href = "http://pl.wikibooks.org/w/index.php?action=edit&title=" + link;
}

pathway.init();

/*
</pre>
*/