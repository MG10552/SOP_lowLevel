/* generated javascript */
var skin = 'monobook';
var stylepath = '/skins-1.5';

/* MediaWiki:Common.js */
/* Umieszczony tutaj kod JavaScript zostanie załadowany przez każdego użytkownika, podczas każdego ładowania strony.
*/

// Frame Busting
if (top != self) top.location.href = self.location.href;

function include(src)
{
   document.write('<script type="text/javascript" src="/w/index.php?title=MediaWiki:' + src + '&amp;action=raw&amp;ctype=text/javascript"><!-- include --></script>');
}

/*
* pageInfo, instrukcja obsługi:
   * pageInfo.namespace          numer przestrzeni nazw (równe wgNamespaceNumber)
   * pageInfo.name               pełna nazwa strony
   * pageInfo.title              tytuł strony, czyli ostatnia część po '/' albo jest równe pageInfo.name, gdy nigdzie nie występuje slash
   * pageInfo.book               tytuł książki
   * pageInfo.action             akcja taka jaka jest w adresie URL pod "action=", w przypadku normalnego czytania strony, action jest równe "get"
   * pageInfo.diff               null w przypadku, gdy nie porównujemy wersji, w przeciwnym wypadku wartość występującą w adresie URL
*/

function PageInfoInit()
{
   var _g = /_/g;
   this.name = wgPageName.replace(/_/g, ' ')
   this.namespace = wgNamespaceNumber;

   var i = this.name.search(/\/[^\/]*$/g);
   this.title = this.name.slice(i + 1);

   this.book = this.name.replace(/\/.*/g, "");

   if ( document.URL.search("http://pl.wikibooks.org/w/index.php") != -1 ) {
      re = /\&diff=/g;
      this.diff = re.test(document.URL);
      re = /\&action=[^\&]*/g;
      this.action = document.URL.match(re);
      if ( this.action == null ) {
         this.action = 'get';
         } else {
            this.action = this.action[0].slice(8, this.action[0].length);
         }
   } else {
      this.diff = null;
      this.action = 'get';
   }
}

var pageInfo = new PageInfoInit();

var extensionsLoaded = false;
addOnloadHook(
   function()
   {
      if ( extensionsLoaded ) return;

      extensionsLoaded = true;
      include("Ext/Pathway.js"); // skrypt odpowiedzialny za generację ścieżki

      if ( document.getElementById('highlighting') ) {
         include("Ext/Highlighting.js"); // podświetla słowa kluczowe w kodach itp.
      }
    }
);

// informuje, czy redirect lub strona do ekspresowego usunięcia jest używana
function showUsedInfo() {
   var name = encodeURIComponent(wgPageName);
   var url = "http://pl.wikibooks.org/w/api.php?action=query&list=embeddedin|backlinks&eititle=" + name + "&bltitle=" + name + "&format=xml";
   var req;
   try {
      req=new ActiveXObject("Msxml2.XMLHTTP");
   } catch (e1) {
      try {
         req=new ActiveXObject("Microsoft.XMLHTTP");
      } catch (e2) {
         req = null;
      }
   }
   if(!req && typeof XMLHttpRequest != "undefined")
      req = new XMLHttpRequest();

   if(!req) return;

   req.open("GET", url, true);
   req.onreadystatechange = function() {
      if(req.readyState == 4)
      {

         var used = -1;
         if(req.status == 200)
         {
            used = req.responseXML.getElementsByTagName("bl").length + req.responseXML.getElementsByTagName("ei").length;
         }

         var el = document.getElementById("ek-info");
         if ( !el ) 
            el = document.getElementById("contentSub");

         var txt = "(problemy z połączeniem)";
         var color = "black";
         if ( used != -1 ) {
            txt = used? "(strona używana)" : "(strona nieużywana)";
            color = used? "blue": "red";
         }
         el.innerHTML += " <span style='font-weight: bold; color:" + color + "'>" + txt + "</span>";
      }
   }
   req.send(null);
}

addOnloadHook(function() {
   if ( document.URL.indexOf("redirect=no") != -1 || document.getElementById("ek-info") ) {
         showUsedInfo();
   }
})

if (window.showModalDialog && document.compatMode && document.compatMode == "CSS1Compat")
{
   var oldWidth;
   var docEl = document.documentElement;

   function fixIEScroll() {
      if (!oldWidth || docEl.clientWidth > oldWidth)
         doFixIEScroll();
      else
         setTimeout(doFixIEScroll, 1);
  
      oldWidth = docEl.clientWidth;
  }

  function doFixIEScroll() {
    docEl.style.overflowX = (docEl.scrollWidth - docEl.clientWidth < 4) ? "hidden" : "";
  }

  document.attachEvent("onreadystatechange", fixIEScroll);
  attachEvent("onresize", fixIEScroll);
}

function addLoadEvent(func)
{
   if (window.addEventListener) 
      window.addEventListener("load", func, false);
   else if (window.attachEvent) 
      window.attachEvent("onload", func);
}

if ( wgPageName == "Wikibooks:Dodatki" ) {
  // dodawanie mikropodsumowania
  // użycie: w [[Wikibooks:Dodatki]]
  // kod: <span class="microsummary"><span>http://blebleble</span><span>tekst</span></span>
  var WARNING = "Potrzebujesz przeglądarki obsługującej mikropodsumowania.";
  function addGenerator(url) {
    if (typeof window.sidebar == "object" &&
        typeof window.sidebar.addMicrosummaryGenerator == "function")
      window.sidebar.addMicrosummaryGenerator(url);
    else
      alert(WARNING);
  }
  addOnloadHook(function() {
   var elements = document.getElementsByTagName("span");
   for ( var i=0; i<elements.length; ++i ) {
      var el = elements[i];
      if ( el.getAttribute("class") == "microsummary" ) {
         var url = el.firstChild.firstChild.data.replace(/\"/g, "\\\""); // ->span1->text
         var anchor = document.createElement("a");
         anchor.href = 'javascript:addGenerator("' + url + '")';
         anchor.appendChild(document.createTextNode(el.lastChild.firstChild.data)); // ->span2->text
         while ( el.firstChild ) el.removeChild(el.firstChild);
         el.appendChild(anchor);
      }
   }
  });
}

/* MediaWiki:Monobook.js */
/* Umieszczony tu kod JavaScript zostanie załadowany wyłącznie przez użytkowników korzystających ze skórki MonoBook

Zobacz też: [[MediaWiki:Common.js]] (JavaScript używany we wszystkich skórkach)

<span id="highlighting" class="lang-js" style="display:none">&nbsp;</span>
__TOC__
<pre>
*/


function LinkFA()
{
   // iterate over all <span>-elements
   for(var i=0; a = document.getElementsByTagName("span")[i]; i++) {
      // if found a FA span
      if(a.className == "FA") {
         // iterate over all <li>-elements
         for(var j=0; b = document.getElementsByTagName("li")[j]; j++) {
            // if found a FA link
            if(b.className == "interwiki-" + a.id) {
               b.style.padding = "0 0 0 16px";
               b.style.backgroundImage = "url('http://upload.wikimedia.org/wikipedia/commons/6/60/LinkFA-star.png')";
               b.style.backgroundRepeat = "no-repeat";
               b.title = "Ten artykuł zdobył wyróżnienie";
            }
         }
      }
   }
}

/*
</pre>

== Poprawki dla strony głównej ==
<pre>
// */

var isDiff = (document.location.search && (document.location.search.indexOf("diff=") != -1 || document.location.search.indexOf("oldid=") != -1));

if (wgPageName == "Wikibooks:Strona_główna" && !isDiff) 
{
   document.write('<style type="text/css">/*<![CDATA[*/ #siteSub, #contentSub, h1.firstHeading { display: none !important; } /*]]>*/</style>');
}

addLoadEvent(LinkFA);

/*
</pre>

== Dynamiczne szablony nawigacyjne ==
<pre>
// */

// ============================================================
// BEGIN Dynamic Navigation Bars

// set up the words in your language
var NavigationBarHide = '[ Ukryj ]';
var NavigationBarShow = '[ Pokaż ]';

// set up max count of Navigation Bars on page,
// if there are more, all will be hidden
// NavigationBarShowDefault = 0; // all bars will be hidden
// NavigationBarShowDefault = 1; // on pages with more than 1 bar all bars will be hidden
var NavigationBarShowDefault = 0;


// shows and hides content and picture (if available) of navigation bars
// Parameters:
//     indexNavBar: the index of navigation bar to be toggled
function toggleNavigationBar(indexNavBar)
{
   var NavToggle = document.getElementById("NavToggle" + indexNavBar);
   var NavFrame = document.getElementById("NavFrame" + indexNavBar);

   if (!NavFrame || !NavToggle)
      return;
        
   // values to be set
   var currDisplay;
   var currTitle;
        
   // if shown now
   if (NavToggle.firstChild.data == NavigationBarHide) {
      currDisplay = 'none';
      currTitle = NavigationBarShow;
   } // if hidden now
   else if (NavToggle.firstChild.data == NavigationBarShow) {
      currDisplay = 'block';
      currTitle = NavigationBarHide;
   }
        
   for (var NavChild=NavFrame.firstChild; NavChild!=null; NavChild=NavChild.nextSibling) {
      if (NavChild.nodeType==1) {      // only if this is an element node
         if (NavChild.className=='NavPic' || NavChild.className=='NavContent')
            NavChild.style.display = currDisplay
         else if (NavChild.className == 'NavToggle')
            NavChild.firstChild.data = currTitle;
      }
   }
}

// adds show/hide-button to navigation bars
function createNavigationBarToggleButton()
{
   // stop before starting
   if (window.createNavigationBarToggleButtonDone)
      return;

   var i;
   var indexNavBar = 0;
   var divs = document.getElementById('bodyContent').getElementsByTagName("div");
   // iterate over all < div >-elements
   for (i=0; i<divs.length; i++) {
      // if found a navigation bar
      if (divs[i].className == "NavFrame") {
         var NavFrame = divs[i];
         indexNavBar++;
         var NavToggle = document.createElement("a");
         NavToggle.className = 'NavToggle';
         NavToggle.setAttribute('id', 'NavToggle' + indexNavBar);
         NavToggle.setAttribute('href', 'javascript:toggleNavigationBar(' + indexNavBar + ');');

         var NavToggleText = document.createTextNode(NavigationBarHide);
         NavToggle.appendChild(NavToggleText);
                        
         // add NavToggle-Button as first div-element 
         // in < div class="NavFrame" >
         NavFrame.insertBefore(NavToggle, NavFrame.firstChild);
         NavFrame.setAttribute('id', 'NavFrame' + indexNavBar);
      }
   }

   // if more Navigation Bars found than Default then hide all
   if (NavigationBarShowDefault < indexNavBar)
   {
      for(i=1; i<=indexNavBar; i++)
         toggleNavigationBar(i);
   }
}

addOnloadHook(createNavigationBarToggleButton);

// END Dynamic Navigation Bars
// ============================================================

/*</pre>
== Wyszukiwanie Google ==
<pre>// */

var googleSearchInitialized = false;
function insertGoogleSearch() {
   if ( wgNamespaceNumber != 0 || googleSearchInitialized ) {
      return;
   }
   googleSearchInitialized = true;

   var google = "http://www.google.com/custom?sa=Google+Search&domains=pl.wikibooks.org/wiki/PAGE&sitesearch=pl.wikibooks.org/wiki/PAGE";
   var tb = document.getElementById('p-tb').getElementsByTagName('ul')[0];
   var link = document.createElement('a');

   var book = pageInfo.book;
   if ( book.length == 1 || book.indexOf('++') != -1 || encodeURIComponent(book) != book ) {
       google = "http://www.google.com/custom?sa=Google+Search&domains=pl.wikibooks.org/wiki/&sitesearch=pl.wikibooks.org/wiki/&q=%22PAGE%22"
   }

   link.href = google.replace(/PAGE/g, encodeURIComponent(book));
   link.appendChild(document.createTextNode("Szukaj w podręczniku"));

   var li = document.createElement('li');
   li.id = "google-trick-search";

   li.appendChild(link);
   tb.insertBefore(li, tb.firstChild);
}

addOnloadHook(insertGoogleSearch);
// ==================
/*
</pre>

== Dodanie linka [edytuj] dla sekcji nagłówkowej ==
* Pomysł: [[w:en:User:Pile0nades]]
* Wykonanie: Maciej Jaros [[w:pl:User:Nux]]
* Licencja: [http://opensource.org/licenses/gpl-license.php GNU General Public License v2]
<pre>
// */
window.disableEditTopLink = true;
function addEditTopLink() {
   //
   // somehow it gets run twice on some pages - stop that
   if (window.addEditTopLinkDone || wgPageName == "Strona_główna" || window.disableEditTopLink)
      return;

   window.addEditTopLinkDone = true;

   //      
   // if this is preview page or there is no edit tab, stop
   if (!wgIsArticle)
      return;

   //
   // Creating elements
   //
   // create div
   var div = document.createElement("DIV");
   div.className = 'editsection';

   // create link
   var link = document.createElement("A");
   link.href = document.getElementById("ca-edit").getElementsByTagName("a")[0].href + '&section=0';
   link.setAttribute('title', 'edytuj sekcję nagłówkową artykułu');
   link.appendChild(document.createTextNode('edytuj'));

   // append link and stuff to div
   div.appendChild(document.createTextNode('['));
   div.appendChild(link);
   div.appendChild(document.createTextNode(']'));

   var bodyContent = document.getElementById("bodyContent");
   bodyContent.parentNode.insertBefore(div, bodyContent);

   div2 = document.createElement("DIV");
   div2.setAttribute("style", "clear: both");
   bodyContent.insertBefore(div2, bodyContent.firstChild);
}

addOnloadHook(addEditTopLink);

/*
</pre>
*/