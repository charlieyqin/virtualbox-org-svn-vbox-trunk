/* $Id$ */
/** @file
 * VBox Qt GUI - VirtualBox Qt extensions: UIFilePathSelector class declaration.
 */

/*
 * Copyright (C) 2008-2013 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifndef ___UIFilePathSelector_h___
#define ___UIFilePathSelector_h___

/* VBox includes */
#include "QIWithRetranslateUI.h"

/* Qt includes */
#include <QComboBox>

/* VBox forward declarations */
class QILabel;
class QILineEdit;

/* Qt forward declarations */
class QHBoxLayout;
class QAction;
class QIToolButton;


class UIFilePathSelector: public QIWithRetranslateUI<QComboBox>
{
    Q_OBJECT;

public:

    enum Mode
    {
        Mode_Folder = 0,
        Mode_File_Open,
        Mode_File_Save
    };

    UIFilePathSelector (QWidget *aParent);
   ~UIFilePathSelector();

    void setMode (Mode aMode);
    Mode mode() const;

    void setEditable (bool aOn);
    bool isEditable() const;

    void setResetEnabled (bool aEnabled);
    bool isResetEnabled () const;

    void setFileDialogTitle (const QString& aTitle);
    QString fileDialogTitle() const;

    void setFileFilters (const QString& aFilters);
    QString fileFilters() const;

    void setDefaultSaveExt (const QString &aExt);
    QString defaultSaveExt() const;

    void resetModified();
    bool isModified() const;
    bool isPathSelected() const;

    QString path() const;

signals:
    void pathChanged (const QString &);

public slots:

    void setPath (const QString &aPath, bool aRefreshText = true);
    void setHomeDir (const QString &aHomeDir);

protected:

    void resizeEvent (QResizeEvent *aEvent);
    void focusInEvent (QFocusEvent *aEvent);
    void focusOutEvent (QFocusEvent *aEvent);
    bool eventFilter (QObject *aObj, QEvent *aEv);
    void retranslateUi();

private slots:

    void onActivated (int aIndex);
    void onTextEdited (const QString &aPath);
    void copyToClipboard();
    void refreshText();

private:

    void changePath (const QString &aPath, bool aRefreshText = true);
    void selectPath();
    QIcon defaultIcon() const;
    QString fullPath (bool aAbsolute = true) const;
    QString shrinkText (int aWidth) const;

    /* Private member vars */
    QAction *mCopyAction;
    Mode mMode;
    QString mPath;
    QString mHomeDir;
    QString mFileFilters;
    QString mDefaultSaveExt;
    QString mFileDialogTitle;
    QString mNoneStr;
    QString mNoneTip;
    bool mIsEditable;
    bool mIsEditableMode;
    bool mIsMouseAwaited;

    bool mModified;
};

#endif /* !___UIFilePathSelector_h___ */
