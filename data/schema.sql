CREATE TABLE `object` (
    'id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    'name' COLLATE NOCASE NOT NULL
);

CREATE UNIQUE INDEX obj_name ON `object`(name);


CREATE TABLE `object_generalization` (
    'id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    'subject' INTEGER REFERENCES `object`(id) ON DELETE CASCADE,
    'generalization' INTEGER REFERENCES `object`(id) ON DELETE CASCADE
);

CREATE UNIQUE INDEX gen_uniq ON `object_generalization`(subject, generalization);


CREATE TABLE `object_composition` (
    'id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    'subject' INTEGER REFERENCES `object`(id) ON DELETE CASCADE,
    'component' INTEGER REFERENCES `object`(id) ON DELETE CASCADE
);

CREATE UNIQUE INDEX com_uniq ON `object_composition`(subject, component);
