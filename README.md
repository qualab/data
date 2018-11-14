data
====

# Obsolete

Further development is at repository:
https://github.com/qualab/dot

# Data Access Technology Algorithms

## Basic terms

D.A.T.A. uses objects to access data and abilities of C++ syntax to build and verify correctness of the data retrievement query.
Every object can be hold in data::object and must be variable of class derived from data::object.
Another words that should be correct:

```
data::object value = data::select().from(users).where(users["type"]=="admin")[0]["login"];
```

for any type requested from data source.

By default D.A.T.A. support limited set of types on data source side, but you may implement your own class derived from data::object and support any custom operations on your class.

## Data types

* object - base type for any data, this class can hold null, any scalar and any of derived data types.
* decimal - helpful class for decimal values with fixed point, support precision up to 18 decimal digits, lossless up to precision specified.
* text - helpful class to handle any textual data in Unicode, ASCII or any known encoding support, it makes encoding transformations wise and lazy, automatic and implicit for comfortable usage of developer.
* datetime - date and time with time zone. Comfortable way to use it locally without think about UTC and pass it out with specification of time zone automaticaly.
* query - constructor to retrieve data from data source, suport basic constructions based on select, update, insert, delete. Useful for to prevent mistakes on the development stage at compile time.
* null - of course any data type supports the case when value is not set and object is in null state.
* memory - useful module to use prepared memory to implace data objects, manage memory for results of data queries and to prevent mistakes and of course do it by fastest way.
* cast - template to trasform any data types between each other, including scalars, textual information. Extendable for any other type.
* ...

## Basic rules

...
