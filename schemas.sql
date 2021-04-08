create table pets(
petid INT NOT NULL UNIQUE,
name CHAR NOT NULL);

create table tags(
tagid INT NOT NULL UNIQUE,
name CHAR NOT NULL,
type CHAR NOT NULL);

create table petTags(
petid INT NOT NULL UNIQUE,
tagid INT NOT NULL UNIQUE);