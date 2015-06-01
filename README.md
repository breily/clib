
clib
====

* C library of data structures, etc.

functions
---------
* list functions
----------------

* blib uses a doubly linked list to wrap void pointers, so you can
  store whatever you want.
* provided functions for indexing/appending/removing, as well as
  functions to treat the list as a stack or a queue.

* basic data type: `struct blist`
* `blist_init()`
* `blist_einit(void **, int)`
* `blist_free(blist *)`
* `blist_length(blist *)`
* `blist_isempty(blist *)`
* `blist_append(blist *, void *)`
* `blist_remove(blist *, int)`
* `blist_at(blist *, int)`
* `blist_push(blist *, void *)`
* `blist_pop(blist *)`
* `blist_peek(blist *)`
* `blist_enqueue(blist *, void *)`
* `blist_dequeue(blist *)`

* string functions
------------------

* blib wraps strings in a struct to track their length and some
  other planned information.
* does not require string.h
* basic data type: `struct bstring`
* `bstring_init(char *)`
* `bstring_length(bstring *)`
* `bstring_contains(bstring *)`
* `bstring_at(bstring *, int)`
* `bstring_equal(bstring *, bstring *)`
* `bstring_concat(bstring *, bstring *)`
* `bstring_nconcat(bstring *, bstring *, int)`
* `bstring_rconcat(bstring *, char *)`
* `bstring_rnconcat(bstring *, char *, int)`

* memory functions
------------------

* blib wraps some functions to print error messages

* `bmalloc(size_t)`
* `bcalloc(size_t, size_t)`
* `brealloc(void *, size_t)`

* functional programming
------------------------

* attempting to add functional concepts to C
* NOTE: this section probably requires more work

* `map(void *(*func)(void *), blistd *)`
* `filter(void *(*func)(void *), blistd *)`

* io functions
--------------

* implement basic io functionality

* `bio_calloc()`
* `bio_free()`
* `breadline(char *)`
* `breadline_map(int (*func)(char *), char *)`

* hash/map functions
---------------------

* hash table implentation
* NOTE: this section require much more work

* `bhash_init()`
* `bhash_lookup(bhash *, void *)`
* `bhash_insert(bhash *, void *, void *)`
* `bhash_remove(bhash *, void *)`
* `__bhash_hash_function(bhash *, void *)`

* trie implementation
---------------------

* extremely early stages

* `btrie_init()`
* `btrie_insert(btrie *, char *, void *)`
* `btrie_lookuo(btrie *, char *)`

